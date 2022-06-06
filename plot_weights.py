#!/usr/bin/env python
import argparse
import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

LINEAR_RAMP=0.045

def plot(dataFrame):
    ax1 = plt.gca()
    ax1.set_ylabel('Weight (lb)')
    #ax2.tick_params('y', colors='red')
    dataFrame.plot(kind='line',x='time (s)',y='weight',ax=ax1)

    plt.show()

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('-f',
		        '--input_file',
                        help="this is the CSV file that contains a time (in seconds) and weight (in lbs). one pair per line",
			default="weight_ramp.csv")

    args = parser.parse_args()

    data = np.genfromtxt(args.input_file, delimiter=',')

    df = pd.DataFrame({
        'time (s)': data[:,0] / 1000,
        'weight': data[:,1],
    })

    plot(df)

