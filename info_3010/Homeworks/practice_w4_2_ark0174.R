#install the packages
#install.packages("rjson")
#install.packages("jsonlite")

#load the packages
library('rjson')
library('jsonlite')

#reading in json file
json_file<-"snowstorm_sample.json"
storm_tweets<-stream_in(file(json_file))

#dimensions of data set
nrow(storm_tweets)
ncol(storm_tweets)

#reading in data
date_time=storm_tweets$created_at
username = storm_tweets$user$screen_name
tweet_text= storm_tweets$text

#checking data
str(date_time)
str(username)
str(tweet_text)

#creating a data frame
df<-data.frame(date_time,username,tweet_text)

#simple summary
head(df)
str(df)
summary(df)

#count number of tweets for each minute
vec_times <- df[,"date_time"]
split_times <- str_split_fixed(vec_times, ":", 3)

min_43 <-0
min_44 <-0
min_45 <-0
for (minute in split_times[,2]) {
  if (minute == "43"){ min_43 <-min_43+1 }
  else if (minute == "44"){ min_44 <- min_44+1 }
  else if (minute == "45"){ min_45 <- min_45+1 }
}
cat("There were:",min_43,"tweets at minute logged 43")
cat("There were:",min_44,"tweets at minute logged 44")
cat("There were:",min_45,"tweets at minute logged 45")


