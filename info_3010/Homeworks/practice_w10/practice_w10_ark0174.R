library(ggplot2)

head(mpg)

#basic distribution plot
ggplot(data = mpg) + geom_point(aes(x = displ, y = hwy, color = class))


#facet wraps
ggplot(mpg) +
  geom_point(aes(displ, hwy)) +
  facet_wrap(~class, nrow=7)

#smooth line
ggplot(mpg) +
  geom_smooth(aes(displ, hwy))

#line per class using linetype
ggplot(mpg) +
  geom_smooth(aes(displ,hwy, linetype = drv))

#line per class using color
ggplot(mpg) +
  geom_smooth(aes(displ,hwy, color = drv))