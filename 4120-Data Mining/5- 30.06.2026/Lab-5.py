from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.naive_bayes import GaussianNB
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix,classification_report

iris = load_iris()
X_train, X_test, y_train, y_test = train_test_split(iris.data,iris.target,test_size=0.2, random_state=42)

models = {
'Decision Tree': DecisionTreeClassifier(max_depth=3),
'Naive Bayes': GaussianNB(),
'Logistic Regression': LogisticRegression(max_iter=200)
}

for name, model in models.items():
    model.fit(X_train, y_train)
    preds = model.predict(X_test)
    print(f"\n{name} Accuracy: {accuracy_score(y_test,preds)*100:.2f}%")
    print(confusion_matrix(y_test, preds))
    
print(classification_report(y_test, preds))