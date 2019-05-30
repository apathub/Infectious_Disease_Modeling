import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
from scipy import stats

df = pd.read_csv('../summary.csv', names = ['step', 'prob_of_transfer', 'per_vaccinated_internal', 'people_Encountered',\
                                           'population_size', 'npeople_Infected', 'npeople_Susceptible', 'npeople_Recovered'])
sns.set(color_codes=True)
# print the univariate distribution plots for each parameter
headers = list(df.columns.values)
sns.distplot(df['step'])
plt.show()