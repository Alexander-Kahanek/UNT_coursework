#install.packages(c("streamR","tm"))

library(streamR)
library(tm)

tweet_df<-parseTweets('snowstorm_sample2.json')

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

myStopwords<-stopwords("english")

myStopwords<-c(stopwords("english"),"while","gonna","much")

myCorpus<-tm_map(myCorpus, removeWords, myStopwords)

myDtm<-TermDocumentMatrix(myCorpus, control = list(minWordLength= 1))

findFreqTerms(myDtm, lowfreq=10)

#install.packages('wordcloud')
library(wordcloud)

inspect(myDtm[266:270,31:40])

m <-as.matrix(myDtm)

v <-sort(rowSums(m), decreasing=TRUE)

d <-data.frame(word=names(v), freq=v)

wordcloud(d$word, d$freq, min.freq=3)
