library(dplyr)
library(ggplot2)
library(caret)
df <- read.csv('HousePrice.csv')

#making life ezpz
tt_split <- function(data, percent, side){
  ## FUNCTION FOR SPLITTING BY PERCENT CHOSEN
  if(side == 'top'){
    data <- data %>% #top X% of data
      slice(1:ceiling(nrow(data)*percent))
  }
  else if (side == 'bot'){
    data <- data %>% #bottom X% of data
      slice(ceiling(nrow(data)*percent)+1:nrow(data))
  }
  return(data)
}

#coninous to classification
df <- df %>% 
  mutate(
    Price = factor(ifelse(Price < 800000, 'low','high'))
  )

#check num of samples each
df %>% 
  subset(select = Price) %>% 
  table()

#split data
train <- df %>% 
  tt_split(0.8, 'top') %>% 
  na.omit() #remove NA

test <- df %>% 
  tt_split(0.8, 'bot') %>% 
  na.omit() #remove NA

#5 fold cross validation, repeat twice
fitControl <- trainControl(
  method = 'repeatedcv',
  number = 5,
  repeats = 2
)

#train model
svmpoly <- train(Price ~ Sqft_Area + Age + Lot_Area + Crime,
                 data = train,
                 method = 'svmPoly',
                 trControl = fitControl)

#check model
svmpoly

#apply model to test data
prediction_svmpoly <- svmpoly %>% 
  predict(newdata=test)

#eval results
confusionMatrix(prediction_svmpoly, test$Price)

#svm with linear kernel
svmlinear <- train(Price ~ Sqft_Area + Age + Lot_Area + Crime,
                   data = train,
                   method = 'svmLinear',
                   trControl = fitControl)

svmlinear

#svm with gaussian kernel
svmradial <- train(Price ~ Sqft_Area + Age + Lot_Area + Crime,
                   data = train,
                   method = 'svmRadial',
                   trControl = fitControl)

svmradial


#guassian kernal seemed to produce the better results
#than the linear kernel