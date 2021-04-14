#course.grades things

course.grades<-c(92,75,46,26,0,100,89,76)
n<-1
while (n<=length(course.grades)) {
  print(course.grades[n])
  n=n+1
}
n<-1
while (n<=length(course.grades)) {
  if (course.grades[n]<60) {
    print("failed")
  } else {
    print("pass")
  }
  n=n+1
}

#function to compute area of ractangle
#using length and width

Compute_area_rect<- function(l,w) {
  area=l*w
  return(area)
}
Compute_area_rect(10,10)