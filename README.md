![stock_stallion_logo](https://github.com/CodeApprenticeRai/StockStallion/blob/master/logos/ss_logo_idea_1-2.png?raw=true)

# StockStallion Reference

StockStallion in a system designed for the viewing, analysis and prediction of performance of stocks. It simplifies investment strategy. 

# Table of Contents

# Architecture

{{{ Ideal Architecture Diagram Goes Here }}}

{{{ Iteration 1 Architecture Diagram Goes Here }}}  

...

{{{ Iteration N Architecture Diagram Goes Here }}}


# Iteration 1 (13/02/2018 - 02/03/2018)

Assignments: 

Tare':

Blake J: 

Blake W:

Justin:

Khaled:CLI (Command Line Interface)

Nathan: 

Tim: 

#### Iteration 1 Stories 
Basic: Application execution will prompt user to either enter username, password or to create a new username and password. On Login User will be prompted by a matrix onsole of stocks names, tickers, and current (or dummy) prices of stocks. Menu options include addition of new stocks by symbol, removal of additional stocks.  

Advanced: Application execution will open a login form with a demo button/option. Demo will not require credentials. On login within demo mode a predetermined portfolio will be rendered as the list view. For first iteration, stock objects contain only price of stock. The data for the demo will be apart of the application. 5 (or some other number) of stocks are listed. User can exit. 

**Research:** 
Rendering Windows and Forms in C++,\n
Displaying Database/File data in Windows, 
...

**Objectives:**
- Create Login View (Demo) 
- Create List View
- ...

**Tasks**
- Create Basic Interface as Described. ...
- Perform GUI research and write a test implementation



#### 

Features for Future Iterations: 
-Central Cloudbased Server and Database
-Login authentication
-Time Series Visualization (?in list view, sepaarate from list view?)
-More Statistics
-Predictive Algorithms for stock / portfolio performance. 



### Command Line Interface
-Upon startup will ask for login and password or to create a new profile.
-If user attempts to log in will read from a file a list of passwords and usernames to find a match
-if user creates a new account will it will save said account to the file
-will prompt user to start a portfolio or go to demo mode
-Demo mode consists of a tutorial of how to use StockStallion and the future values of various stock objects
-Portfolio mode will allow user to make their portfolio and show a list of stock objects and their current values
-once portfolio is made, user must specify this, StockStallion will perform it's task and show predicted results







# Documentation 

/// this will be moved to somewhere more dedicated.  ////

**Template**

|--------

class classname ( argumentype argument...)

⋅⋅⋅class description

classmethod methodname( argumenttype argument..)

⋅⋅⋅method description
return type, return description

------|




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

