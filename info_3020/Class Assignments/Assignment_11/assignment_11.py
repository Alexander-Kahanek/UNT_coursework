import pymysql
import csv
import pandas as pd
from datetime import datetime


filename = "assign11-1-ch02-data.csv"

def importData(fn):
    with open(fn) as f:
        reader = csv.reader(f)
        next(reader)
        for row in reader:
            pydb = pymysql.connect("localhost", "root", "MW$^cb77", "pydb")
            dbcursor = pydb.cursor()
            sql = "insert into assignment_11_dn(dates,nums) values(%s,%s)"
            date = row[0]
            numbs = row[1]
            values = (date, numbs)
            dbcursor.execute(sql, values)
            pydb.commit()
            dbcursor.close()

def sumSQL(output_fn):
    pydb = pymysql.connect("localhost", "root", "MW$^cb77", "pydb")
    dbcursor = pydb.cursor()
    sql = "select dates, sum(nums) from assignment_11_dn group by dates"
    dbcursor.execute(sql)
    results = dbcursor.fetchall()
    dbcursor.close()
    pydb.close()

    for row in results:
        df = pd.DataFrame([{'dates':row[0], 'numbers':row[1]}])
        df.to_csv(output_fn, mode='a',header=False) #could not get function to work with xlsx, file was corrupt
        # write = pd.ExcelWriter(output_fn)
        # df.to_excel(write, columns=['dates','numbers'], index=False, encoding='utf-8', sheet_name='sheet')
        # write.save()
        # df.to_csv(output_fn, columns=['dates','numbers'], index=False, sep=',')

def getBestFood(day, fn):
    day = datetime.strptime(day, '%Y-%m-%d')
    df = pd.read_excel(fn)
    max = df.max(axis=1)
    print("Column Name, Max Value:")
    for i in range(len(df)):
        if df['sale date'][i] == day:
            row = df.loc[i][1:11]
            col=0 #keeping track of column value
            for k in row:
                col = col+1
                if k == max[i]:
                    print(df.columns.values[col],"," ,k)



#import data function
importData(filename) #import data into sql

#find sum of sql db
sumSQL("output.csv") #outputs to csv, xlsx file was corrupted...

#get most sold food by date
getBestFood('2015-1-1','assign11-1-catering_sale_all.xls')


