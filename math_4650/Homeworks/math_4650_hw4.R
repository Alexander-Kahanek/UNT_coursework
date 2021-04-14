lambda_1<-rgamma(1000, 102.5,scale=1/20.5)
lambda_1<-sort(lambda_1)
plot(lambda_1,dgamma(lambda_1,102.5,scale=1/20.5),type="l",main="plot of posterior lambda",ylab="probability densitry", col = "black")

par(new=TRUE)

lambda_2<-rgamma(1000, 102.25,scale=1/20.025)
lambda_2<-sort(lambda_2)
plot(lambda_2,dgamma(lambda_2,102.25,scale=1/20.025),type="l",main="plot of posterior lambda",ylab="probability densitry", col = "blue")
