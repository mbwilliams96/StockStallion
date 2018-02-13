![stock_stallion_logo](https://github.com/CodeApprenticeRai/StockStallion/blob/master/logos/ss_logo_idea_1-2.png?raw=true)

# StockStallion Documentation


### User Object 
-User has username.  
-User has password.   
User has portfolio full of equity securities.  
User can have bio  


### Stock Object
-stock object contains current price  
stock object can contain ytd return  
stock object can contain 5 month moving average of price (1 week granularity)   
stock object include 1 yr volatility average  
stock object contains brief description of company  
stock object contains % return over past day, week, month, year  
(we may need live date updates)  
future update of predictive features  


### Portfolio Object
contains collection of equity securities  
contains beta (risk) variable  
matches (or normalizes returns) to probability distribution  
in future can optimize distribution of risks among stocks to reduce overall risk  

### Views

#### Login View
Render Login Form with Username (and/or password), Login Button, Demo Button. 


#### Portfolio List View 
Renders Users Portfolio, which lists stocks

#### User Profile View
Shows information about user (may not be necessary)

## Iteration 1 (13/02/2018 - ?20/02/2018)

#### Iteration 1 Story 
Application execution will open a login form with a demo button/option. Demo will not require credentials. On login within demo mode a predetermined portfolio will be rendered as the list view. For first iteration, stock objects contain only price of stock. The data for the demo will be apart of the application. 5 (or some other number) of stocks are listed. User can exit. 

#### Research: 
Rendering Windows and Forms in C++,\n
Displaying Database/File data in Windows, 
...

#### Objectives:
- Create Login View (Demo) 
- Create List View
- ...


Features for Future Iterations: 
-Central Cloudbased Server and Database
-Login authentication
-Time Series Visualization (?in list view, sepaarate from list view?)
-More Statistics
-Predictive Algorithms for stock / portfolio performance. 
