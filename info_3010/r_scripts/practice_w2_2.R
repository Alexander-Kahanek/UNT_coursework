Grades <- c(98,56,78,46,87,21)
Students <- c("Alex","John","Katie","Beth","Dave","Steve")
names(Grades)<-Students

#cut grades into 3 categories
grade.range <- cut(Grades,3)
print(grade.range)

#how many students in each range?
table(grade.range)

#statistical description of the grades
summary(Grades)

#who has a grade less than 60?
Grades[Grades<60]