#install.packages("RCurl")
library(RCurl)
fileURL = 'https://www.unt.edu'
xData <- getURL(fileURL)
xData
