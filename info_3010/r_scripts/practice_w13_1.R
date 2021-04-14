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
  else{
    print("choose top or bot portion of data")
  }
  return(data)
}

#continuous to categorical
df <- df %>% 
  mutate(
    Price = factor(ifelse(Price < 1000000,'low','high'))
  )

#sample size of each
df %>% 
  subset(select = Price) %>% 
  table()

train <- df %>% #first 80% of data
  tt_split(0.8,'top')

test <- df %>% #last 20% of data
  tt_split(0.8,'bot')


#build model
glm.fit <- glm(Price ~ Sqft_Area + Lot_Area + Age + Crime,
               data=train,
               family=binomial)

glm.fit %>% #summary of linear model
  summary()

#predictions
predictedprob <- glm.fit %>% 
  predict(newdata= test, type="response")

predictedprob %>% 
  head()

#check probability
newdata <- data.frame(test$Sqft_Area, test$Price, predictedprob)

newdata %>% 
  head()

#graphing
newdata %>% 
  ggplot(aes(x=test.Sqft_Area, y=predictedprob)) +
    geom_point()

#evaluation
cfm <- newdata %>% 
  mutate(
    pred = factor(ifelse(predictedprob > 0.5, 'low', 'high'))
  )

confusionMatrix(cfm$test.Price, cfm$pred)
