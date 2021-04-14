df <- read.csv("2010_school_grants.csv")
head(df,5)
summary(df)

#Other fun stuff for me // finding average award (in thousands)
#install.packages("stringr")
library(stringr)

award_amnt <- unique(df[,"X2010.11.Award.Amount"])
#head(award_amnt,50)
amnt_split <-str_split_fixed(award_amnt, ",", 2)
#head(amnt_split)
thousands <- substring(amnt_split[,1],2)
#head(thousands,50) #only the amounts in thousands

total <- 0
count <- 1
for (number in thousands){
  if (str_detect(number,".00",negate= TRUE) & number != "") {
    total[count] <- (as.numeric(number)*1000)
   count <- count +1
  }
}

#Of schools that were given over $1000
cat("the mininum given was:",min(total))
cat("the maximum given was:",max(total))
cat("the average given was:",mean(total))