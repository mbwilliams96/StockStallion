![stock_stallion_logo](./logos/ss_logo_idea_1-2)

# StockStallion Documentation


### User Object 
User has username.  
User has password.   
User has portfolio full of equity securities.  
User can have bio  


### Stock Object
stock object contains current price  
stock object contains ytd return  
stock object contains 5 month moving average of price (1 week granularity)   
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

#### List View 
