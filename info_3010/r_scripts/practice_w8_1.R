library(ggplot2)

df <- read.csv('World_Happiness_2015_2017.csv')
head(df)
#removing columns that we can't quantify
df_cut <- subset(df, select = -c(Year,Country,Happiness.Rank))
head(df_cut)


#Scatter plot matrix
pairs(df_cut, main = "World Happiness Scatter Plots")
##summary
  #We can see high correlation between
    #happiness and economy
    #happiness and family
    #happiness and health
  #The graph matrix is very difficult to read
  #however it is useful to get a quick easy look at our data


#line plot
USdf <- df[df[,"Country"]== "United States",]
head(USdf)
ggplot(data = USdf, aes(x= USdf$Year, y= USdf$Happiness.Score, group = 1)) + geom_line() + geom_point()

##summary
  #From this linegraph we can see the US  happiness
  #score drop over the three years, from 7.12 to below 7.
  #This chare serves better for frequency type data.