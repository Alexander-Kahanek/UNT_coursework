# -*- coding: utf-8 -*-
# Problem Set 5: Experimental Analysis
# Name: Alexander kahanek
# Time:

import pylab
import re
import numpy as np
# cities in our weather data
CITIES = [
    'BOSTON',
    'SEATTLE',
    'SAN DIEGO',
    'PHILADELPHIA',
    'PHOENIX',
    'LAS VEGAS',
    'CHARLOTTE',
    'DALLAS',
    'BALTIMORE',
    'SAN JUAN',
    'LOS ANGELES',
    'MIAMI',
    'NEW ORLEANS',
    'ALBUQUERQUE',
    'PORTLAND',
    'SAN FRANCISCO',
    'TAMPA',
    'NEW YORK',
    'DETROIT',
    'ST LOUIS',
    'CHICAGO'
]

TRAINING_INTERVAL = range(1961, 2010)
TESTING_INTERVAL = range(2010, 2016)

"""
Begin helper code
"""
class Climate(object):
    """
    The collection of temperature records loaded from given csv file
    """
    def __init__(self, filename):
        """
        Initialize a Climate instance, which stores the temperature records
        loaded from a given csv file specified by filename.
        Args:
            filename: name of the csv file (str)
        """
        self.rawdata = {}

        f = open(filename, 'r')
        header = f.readline().strip().split(',')
        for line in f:
            items = line.strip().split(',')

            date = re.match('(\d\d\d\d)(\d\d)(\d\d)', items[header.index('DATE')])
            year = int(date.group(1))
            month = int(date.group(2))
            day = int(date.group(3))

            city = items[header.index('CITY')]
            temperature = float(items[header.index('TEMP')])
            if city not in self.rawdata:
                self.rawdata[city] = {}
            if year not in self.rawdata[city]:
                self.rawdata[city][year] = {}
            if month not in self.rawdata[city][year]:
                self.rawdata[city][year][month] = {}
            self.rawdata[city][year][month][day] = temperature
            
        f.close()

    def get_yearly_temp(self, city, year):
        """
        Get the daily temperatures for the given year and city.
        Args:
            city: city name (str)
            year: the year to get the data for (int)
        Returns:
            a 1-d pylab array of daily temperatures for the specified year and
            city
        """
        temperatures = []
        assert city in self.rawdata, "provided city is not available"
        assert year in self.rawdata[city], "provided year is not available"
        for month in range(1, 13):
            for day in range(1, 32):
                if day in self.rawdata[city][year][month]:
                    temperatures.append(self.rawdata[city][year][month][day])
        return pylab.array(temperatures)

    def get_daily_temp(self, city, month, day, year):
        """
        Get the daily temperature for the given city and time (year + date).
        Args:
            city: city name (str)
            month: the month to get the data for (int, where January = 1,
                December = 12)
            day: the day to get the data for (int, where 1st day of month = 1)
            year: the year to get the data for (int)
        Returns:
            a float of the daily temperature for the specified time (year +
            date) and city
        """
        assert city in self.rawdata, "provided city is not available"
        assert year in self.rawdata[city], "provided year is not available"
        assert month in self.rawdata[city][year], "provided month is not available"
        assert day in self.rawdata[city][year][month], "provided day is not available"
        return self.rawdata[city][year][month][day]

def se_over_slope(x, y, estimated, model):
    """
    For a linear regression model, calculate the ratio of the standard error of
    this fitted curve's slope to the slope. The larger the absolute value of
    this ratio is, the more likely we have the upward/downward trend in this
    fitted curve by chance.
    
    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        estimated: an 1-d pylab array of values estimated by a linear
            regression model
        model: a pylab array storing the coefficients of a linear regression
            model
    Returns:
        a float for the ratio of standard error of slope to slope
    """
    assert len(y) == len(estimated)
    assert len(x) == len(estimated)
    EE = ((estimated - y)**2).sum()
    var_x = ((x - x.mean())**2).sum()
    SE = pylab.sqrt(EE/(len(x)-2)/var_x)
    return SE/model[0]

"""
End helper code
"""

def generate_models(x, y, degs):
    """
    Generate regression models by fitting a polynomial for each degree in degs
    to points (x, y).
    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        degs: a list of degrees of the fitting polynomial
    Returns:
        a list of pylab arrays, where each array is a 1-d array of coefficients
        that minimizes the squared error of the fitting polynomial
    """
    # generates models
    return [pylab.polyfit(x, y, deg) for deg in degs]


def r_squared(y, estimated):
    """
    Calculate the R-squared error term.
    
    Args:
        y: 1-d pylab array with length N, representing the y-coordinates of the
            N sample points
        estimated: an 1-d pylab array of values estimated by the regression
            model
    Returns:
        a float for the R-squared error term
    """
    # finding r squared values
    mean_y = sum(y)/float(len(y))
    y_sample_est = np.array(y) - np.array(estimated)
    y_sample_mean = np.array(y)-mean_y
    return 1 - float(sum(y_sample_est**2))/sum(y_sample_mean**2)


def evaluate_models_on_training(x, y, models):
    """
    For each regression model, compute the R-squared value for this model with the
    standard error over slope of a linear regression line (only if the model is
    linear), and plot the data along with the best fit curve.
    For the plots, you should plot data points (x,y) as blue dots and your best
    fit curve (aka model) as a red solid line. You should also label the axes
    of this figure appropriately and have a title reporting the following
    information:
        degree of your regression model,
        R-square of your model evaluated on the given data points,
        and SE/slope (if degree of this model is 1 -- see se_over_slope). 
    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        models: a list containing the regression models you want to apply to
            your data. Each model is a pylab array storing the coefficients of
            a polynomial.
    Returns:
        None
    """ 
    # evaluates model on training
    for model in models:
        # setup figure and plot points
        pylab.figure()
        pylab.scatter(x, y, color='blue')

        # find y estimate and r^2
        i = len(model.tolist())
        y_est = np.array([0.]*len(x))
        for c in model:
            y_est += np.array([ c*k**(i-1) for k in x])
            i-=1
        r_2 = r_squared(y, y_est)
        
        # plot line
        pylab.plot(x, y_est, color='red')
        pylab.legend()
        pylab.xlabel('Years')
        pylab.ylabel('Temperature')
        
        # choose title to have
        deg = len(model.tolist())-1
        if deg == 1:
            se_over_sl = se_over_slope(np.array(x), np.array(y), y_est, model)
            title = 'degree of model: {} \n R^2: {} \n SE/slope: {}'.format(deg,  r_2, se_over_sl)
        else:
            title = 'degree of model: {} \n R^2: {}'.format(deg,  r_2)
        
        pylab.title(title)
        pylab.show()
        

def gen_cities_avg(climate, multi_cities, years):
    """
    Compute the average annual temperature over multiple cities.
    Args:
        climate: instance of Climate
        multi_cities: the names of cities we want to average over (list of str)
        years: the range of years of the yearly averaged temperature (list of
            int)
    Returns:
        a pylab 1-d array of floats with length = len(years). Each element in
        this array corresponds to the average annual temperature over the given
        cities for a given year.
    """  
    # generates average temperature for cities
    yearly_avg_y=[] 
    for year in years: # cycle years
        avg_temp = 0
        for city in multi_cities: # cycle cities
            yearly_temp = climate.get_yearly_temp(city, year)
            avg_temp += sum(yearly_temp)/float(len(yearly_temp)) 
        y_avg_temp = float(avg_temp)/len(multi_cities) # average out temp
        yearly_avg_y.append(y_avg_temp)
    return yearly_avg_y

def moving_average(y, window_length):
    """
    Compute the moving average of y with specified window length.
    Args:
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        window_length: an integer indicating the window length for computing
            moving average
    Returns:
        an 1-d pylab array with the same length as y storing moving average of
        y-coordinates of the N sample points
    """
    # finds moving average for the window length given
    y_res = []
    for k in range(len(y)):
        valid_elements = 0
        sum_window_elements = 0
        for i in range(window_length):
            if k-i >= 0:
                valid_elements += 1 # rolling n
                sum_window_elements += y[k-i] # rolling sum
        y_res.append(float(sum_window_elements)/valid_elements)
    return y_res


def rmse(y, estimated):
    """
    Calculate the root mean square error term.
    Args:
        y: an 1-d pylab array with length N, representing the y-coordinates of
            the N sample points
        estimated: an 1-d pylab array of values estimated by the regression
            model
    Returns:
        a float for the root mean square error term
    """ 
    # returns rmse
    return np.sqrt(sum((y - estimated)**2)/float(len(y)))


def gen_std_devs(climate, multi_cities, years):
    """
    For each year in years, compute the standard deviation over the averaged yearly
    temperatures for each city in multi_cities. 
    Args:
        climate: instance of Climate
        multi_cities: the names of cities we want to use in our std dev calculation (list of str)
        years: the range of years to calculate standard deviation for (list of int)
    Returns:
        a pylab 1-d array of floats with length = len(years). Each element in
        this array corresponds to the standard deviation of the average annual 
        city temperatures for the given cities in a given year.
    """
    # generate standard deviations per year
    yearly_avg_y = [] 
    for year in years: # cycle years
        yearly_temp = 0
        for city in multi_cities: # cycle cities
            yearly_temp += climate.get_yearly_temp(city, year) # rolling yearly temp
        y_avg_temp = yearly_temp/float(len(multi_cities)) # average out temp to cities
        mean = sum(y_avg_temp)/float(len(y_avg_temp)) # find average temp
        SS = 0
        for sample in y_avg_temp:
            SS += (sample - mean)**2 # get sum of squares
        yearly_avg_y.append(np.sqrt(float(SS)/len(y_avg_temp)))
    return yearly_avg_y

def evaluate_models_on_testing(x, y, models):
    """
    For each regression model, compute the RMSE for this model and plot the
    test data along with the model’s estimation.
    For the plots, you should plot data points (x,y) as blue dots and your best
    fit curve (aka model) as a red solid line. You should also label the axes
    of this figure appropriately and have a title reporting the following
    information:
        degree of your regression model,
        RMSE of your model evaluated on the given data points. 
    Args:
        x: an 1-d pylab array with length N, representing the x-coordinates of
            the N sample points
        y: an 1-d pylab array with length N, representing the y-coordinates ofd
            the N sample points
        models: a list containing the regression models you want to apply to
            your data. Each model is a pylab array storing the coefficients of
            a polynomial.
    Returns:
        None
    """
    # evaluates and plots model
    for model in models:
        # setup figure and plot points
        pylab.figure()
        pylab.scatter(x,y,color='blue')

        # find rmse
        i = len(model.tolist())
        y_est = np.array([0.]*len(x))
        for c in model:
            y_est += np.array([ c*each**(i-1) for each in x])
            i-=1
        rmse_y = rmse(y, y_est)
        
        # plot line
        pylab.plot(x,y_est,color='red',)
        pylab.legend()
        pylab.xlabel('Years')
        pylab.ylabel('Temperature')
        pylab.title('degree of model: {} \n RMSE: {}'.format(len(model.tolist())-1,  rmse_y))
    pylab.show()

if __name__ == '__main__':

    ##### SETUP MAIN VARIABLES
    climate_data = Climate('data.csv')
    window_length = 5

    # training average temps
    yearly_avg_temps_train = gen_cities_avg(climate_data, CITIES, TRAINING_INTERVAL)
    y_rolling_avg_temps_train = moving_average(yearly_avg_temps_train, window_length)
    
    yearly_avg_temps_test = gen_cities_avg(climate_data, CITIES, TESTING_INTERVAL)
    y_rolling_avg_temps_test = moving_average(yearly_avg_temps_test, window_length)

    # Part A.4
    # load data
    print('part A.4 I')
    y_jan_10 = [climate_data.get_daily_temp('NEW YORK', 1, 10, x) for x in TRAINING_INTERVAL] 
    evaluate_models_on_training(TRAINING_INTERVAL
                                ,y_jan_10
                                ,generate_models(TRAINING_INTERVAL, y_jan_10, [1]))
    
    # #A.4.II
    print('part A.4 II')
    # gett yeaarly avergae temp for new york
    yearly_avg_NY = [] 
    for x in TRAINING_INTERVAL:
        yearly_temp = climate_data.get_yearly_temp('NEW YORK', x)
        avg_temp = sum(yearly_temp)/float(len(yearly_temp)) 
        yearly_avg_NY.append(round(avg_temp,2))
    evaluate_models_on_training(TRAINING_INTERVAL
                                ,yearly_avg_NY
                                ,generate_models(TRAINING_INTERVAL, yearly_avg_NY, [1]))


    # Part B
    print('part B')
    evaluate_models_on_training(TRAINING_INTERVAL
                                ,yearly_avg_temps_train
                                ,generate_models(TRAINING_INTERVAL, yearly_avg_temps_train, [1]))

    # Part C
    print('part C')
    evaluate_models_on_training(TRAINING_INTERVAL
                                ,y_rolling_avg_temps_train
                                ,generate_models(TRAINING_INTERVAL, y_rolling_avg_temps_train, [1]))

    # Part D.2
    # TESTING INTERVAL
    print('part D.2 I')
    evaluate_models_on_training(TRAINING_INTERVAL
                                ,y_rolling_avg_temps_train
                                ,generate_models(TRAINING_INTERVAL, y_rolling_avg_temps_train, [1, 2, 20]))
    
    print('part D.2 II')
    evaluate_models_on_testing(TESTING_INTERVAL
                               ,yearly_avg_temps_test
                               ,generate_models(TESTING_INTERVAL, y_rolling_avg_temps_test, [1, 2, 20]))
    
    # Part E
    print('part E')
    yearly_avg_std_train = gen_std_devs(climate_data, CITIES, TRAINING_INTERVAL)
    y_rolling_avg_std_train = moving_average(yearly_avg_std_train, window_length)
    evaluate_models_on_training(TRAINING_INTERVAL
                                ,y_rolling_avg_std_train
                                ,generate_models(TRAINING_INTERVAL, y_rolling_avg_std_train, [1]))
