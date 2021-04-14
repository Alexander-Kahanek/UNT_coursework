class Document:

    def __init__(self, authors, date):
        self.authors = authors
        self.date = date

    def getAuthors(self):
        return self.authors

    def addAuthor(self, name):
        self.authors.append(name)

    def getDate(self):
        return self.date

class Book(Document):

    def __init__(self, authors, date, title):
        super().__init__(authors, date)
        self.title = title

    def getTitle(self):
        return self.title

class EMail(Document):

    def __init__(self, authors, date, subject, to):
        super().__init__(authors, date)
        self.subject = subject
        self.to = to

    def getSubject(self):
        return self.subject

    def getTo(self):
        return self.to


import pylab
xVals = [4, 7, 9, 11]
yVals1 = [0, 3, 4, 3]
yVals2 = [0, 5, 1, 4]
pylab.plot(xVals, yVals1, '-', label='Test1')
pylab.plot(xVals, yVals2, '--', label='Test2') 
pylab.legend()
pylab.show()
