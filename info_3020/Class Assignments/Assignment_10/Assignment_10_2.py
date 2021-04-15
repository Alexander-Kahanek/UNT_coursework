import pymysql
import random as r

def addStudent(numStudents):

    for i in range(numStudents):
        pydb = pymysql.connect("localhost","root","MW$^cb77","pydb")
        dbcursor = pydb.cursor()
        sql = "insert into tstudent(stuname,major,stuyear,tuition) values(%s,%s,%s,%s)"

        stuname = input("Please enter the name of student {0}: ".format(i+1))
        major = input("Please enter the major of student {0}: ".format(i+1))
        stuyear = int(input("Please enter the graduation year of student {0}: ".format(i+1)))
        tuition = float(input("Please enter the tuition amount of student {0}: ".format(i+1)))

        values=(stuname, major, stuyear,tuition)
        dbcursor.execute(sql,values)

        pydb.commit()
        dbcursor.close()

def deleteStudent():
    pydb = pymysql.connect("localhost", "root", "MW$^cb77", "pydb")
    dbcursor = pydb.cursor()

    sql = "delete from tstudent where stuid=%s"
    values = int(input("Please enter the stuid of who to delete: "))
    dbcursor.execute(sql, values)

    pydb.commit()
    dbcursor.close()

def updateStudent():
    pydb = pymysql.connect("localhost", "root", "MW$^cb77", "pydb")
    dbcursor = pydb.cursor()

    sql = "update tstudent set stuname=%s where stuid=%s"
    stuid = int(input("Please enter the stuid of who to update: "))
    stuname = input("Please enter the name of the student: ")

    values = (stuname, stuid)
    dbcursor.execute(sql, values)

    pydb.commit()
    dbcursor.close()

def countMajor():
    pydb = pymysql.connect("localhost", "root", "MW$^cb77", "pydb")
    dbcursor = pydb.cursor()

    sql = "select major, count(*) from tstudent where major=%s"
    values = input("Please enter the Major that you are looking for: ")
    dbcursor.execute(sql, values)
    results = dbcursor.fetchall()

    print("Count \t Major")
    print("--------------------")
    print(results[0][1], "\t",results[0][0])
    print("--------------------")

    dbcursor.close()
    results=""
    pydb.close()

def getRandStudent():
    pydb = pymysql.connect("localhost", "root", "MW$^cb77", "pydb")
    dbcursor = pydb.cursor()

    sql = "select * from tstudent"
    dbcursor.execute(sql)
    results = dbcursor.fetchall()


    rand = r.randint(1,len(results)-1)

    print("stuid \t stuname")
    print("--------------------")
    print(results[rand][0], "\t",results[rand][1])
    print("--------------------")

    dbcursor.close()
    results=""
    pydb.close()

addStudent(10)
deleteStudent()
updateStudent()
countMajor()
getRandStudent()

