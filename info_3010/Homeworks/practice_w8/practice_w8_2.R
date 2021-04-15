library(ggplot2)
library(MASS)
df <- read.csv('MigrantLocal.csv')

ggplot(df) + geom_density(aes(x= mobdistance, colour=surveytype)) +
  ggtitle("Density of Mobility Distand for Migrants and Locals")

#applying boxcox transformation
b = boxcox(mobdistance~surveytype, data = df)
l = which(b$y == max(b$y))
lambda = b$x[l]

df$postboxcox <- (df$mobdistance^lambda-1)/lambda

ggplot(df) +
  geom_density(aes(x=postboxcox, colour = surveytype)) +
  ggtitle("Density of Mobility Distance")
