library(streamR)
library(tm)

filepath= '/Users/lingzi/Documents/Teaching/INFO3010/Week7'
setwd(filepath)

tweet_df<-parseTweets(tweets='snowstorm_sample2.json')

head(tweet_df)
str(tweet_df)
summary(tweet_df)

textdf<-tweet_df$text

myCorpus<-Corpus(VectorSource(textdf))

myCorpus

inspect(myCorpus[1:3])

myCorpus<-tm_map(myCorpus, tolower)

inspect(myCorpus[1:3])

myCorpus<-tm_map(myCorpus, removePunctuation)
inspect(myCorpus[1:3])

myCorpus<-tm_map(myCorpus, removeNumbers)
inspect(myCorpus[1:3])

myDtm<-TermDocumentMatrix(myCorpus, control = list(minWordLength= 1))

findFreqTerms(myDtm, lowfreq=20)
