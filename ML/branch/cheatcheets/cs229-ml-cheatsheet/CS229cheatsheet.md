# This is my ML cheatsheet,  since I start learning ML from a total beginner level, so this beginner point of view may help you understand.

## Introducing to supervised learning
- discriminative model V.S. generative model
![](/pages-to-jpg/cs229-ml-cheatsheet/difference%20between%20discriminative%20and%20generative%20model.png)
You can distinguish them by their goal.  
The discriminative model only cares the result *y* when given *x*, which means it will not learn the pattern of x at all, it only learns the mapping relationship between *x* and *y*;  
As the generative model first learn the pattern and feature of *x* ($P(x | y)$), and when x is input and we need to categorize it: $P(y|x)$, based on the learned feature of *x*, use Bayes we can calculate: $$P(y|x) = {P(x|y)P(y)\over P(x)}$$   
There's an example to understand the difference:  
    
    - discriminative model: it can only discriminate cat and dog, when a duck inputted, since model haven't learnt what dog and cat is, it will wrongly  categorize the duck into one of cat and dog.
    - generative model: But since this guy learns the feature of the input firstly, it can distinguish the duck neither like cat nor dog, the model will raise an outlier.
    - For some reason,  generative model optimize faster, thus better for small data case.  
    Why faster? Because they make stronger assumptions about the data shape (e.g., assuming it's a Gaussian distribution). They need less data to estimate simple parameters like mean and variance, making them robust for small datasets.
## Notations and General concepts
![](/pages-to-jpg/cs229-ml-cheatsheet/notation-concept.png)
### *Loss function
SVMs are often used in classification tasks, they distinguish between 2 classes by finding the optimal hyperplane which maximize the marigin between the closest data points of opposite classes.  
![](/pages-to-jpg/cs229-ml-cheatsheet/svm.png)
The introduction to Hingen loss and algorithm SVM:
- ***support vectors*** go through the points which define the max margin.
- ***margin*** is a boundary(street) to divide 2 classes(communities)
- ***Optimal hyperplane*** is the plane which maximizes the margin.
The function of hyperplane is: $wx+b = 0$, where w and x are vectors.