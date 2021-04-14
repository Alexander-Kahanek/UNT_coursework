#install.packages("XML",dependencies = TRUE)
library(XML)
library(RCurl)

fileURL = "https://www.redfin.com/city/5155/CO/Denver"
redfindata <- getURL(fileURL)
#redfindata

doc <- htmlTreeParse(redfindata, useInternalNodes = T)
root = xmlRoot(doc)
xmlSApply(root, xmlName)
xmlSApply(root, xmlSize)

head = xmlChildren(root)$head
xmlSApply(head,xmlName)
xmlSApply(head, xmlSize)

body = xmlChildren(root)$body
xmlSApply(body, xmlName)
xmlSApply(body, xmlSize)

main = getNodeSet(doc, "//body")
zest <- lapply(main, xpathSApply, './/div[@class="homeAddressV2"]',xmlValue)
price <- lapply(main, xpathSApply, './/span[@class="homecardV2Price"]',xmlValue)
house <- lapply(main, xpathSApply, './/div[@class="stats"]',xmlValue)

unlist(zest)
unlist(price)
unlist(house)
