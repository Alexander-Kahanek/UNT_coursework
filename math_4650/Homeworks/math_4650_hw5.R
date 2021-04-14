mu <- seq(-2, 2, by=0.1)
mu

# x_0 values from homework #######
# n = 25
x0_pa <- 3.2897
x0_pb <- 3.9199
# n = 100
x0_pc <- 3.2897
x0_pd <- 3.9199

# normal distributions #######
# n = 25
power_pa <- 2 * pnorm(x0_pa, mean = mu, sd = 1, lower.tail = FALSE)
power_pb <- 2 * pnorm(x0_pb, mean = mu, sd = 1, lower.tail = FALSE)
# n = 100
power_pc <- 2 * pnorm(x0_pa, mean = mu, sd = 1, lower.tail = FALSE)
power_pd <- 2 * pnorm(x0_pb, mean = mu, sd = 1, lower.tail = FALSE)

# plotting #########
par(mfrow = c(2,2))

plot(power_pa, main = "n = 25, alpha = 0.1")
plot(power_pb, main = "n = 25, alpha = 0.05")

plot(power_pc, main = "n = 100, alpha = 0.1")
plot(power_pd, main = "n = 100, alpha = 0.05")