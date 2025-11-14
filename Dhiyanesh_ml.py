[14/11, 9:12 am] DHIYANESH🦇☄️: import seaborn as sns

# Get correlation of each feature
corrmat = data.corr()
top_corr_features = corrmat.index

# Plot heatmap
plt.figure(figsize=(20, 20))
sns.heatmap(data[top_corr_features].corr(), annot=True, cmap="RdYlGn")
plt.show()
[14/11, 9:13 am] DHIYANESH🦇☄️: from sklearn.ensemble import ExtraTreesClassifier
import matplotlib.pyplot as plt

# Train ExtraTreesClassifier model
model = ExtraTreesClassifier()
model.fit(X, y)

# Print feature importances
print(model.feature_importances_)

# Plot graph of feature importances
feat_importances = pd.Series(model.feature_importances_, index=X.columns)
feat_importances.nlargest(10).plot(kind='barh')
plt.show()
[14/11, 9:13 am] DHIYANESH🦇☄️: # Import required libraries
import pandas as pd
import numpy as np
from sklearn.feature_selection import SelectKBest
from sklearn.feature_selection import chi2

# Load the dataset
data = pd.read_csv("train.csv")

# Define independent and dependent variables
X = data.iloc[:, 0:20]     # independent features
y = data.iloc[:, -1]       # target variable (price_range)

# Apply SelectKBest class to extract top 10 best features
bestfeatures = SelectKBest(score_func=chi2, k=10)
fit = bestfeatures.fit(X, y)

# Convert the scores into a DataFrame
dfscores = pd.DataFrame(fit.scores_)
dfcolumns = pd.DataFrame(X.columns)

# Combine both DataFrames for better visualization
featureScores = pd.concat([dfcolumns, dfscores], axis=1)
featureScores.columns = ['Specs', 'Score']   # naming columns

# Display the top 10 best features based on Chi-Square test
print(featureScores.nlargest(10, 'Score'))
