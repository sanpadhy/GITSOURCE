
def decToHex(X): 
    hexForm = ['0'] * 100;  

    i = 0; 
    while(X != 0): 
        temp = 0; 

        temp = X % 16; 

        if(temp < 10): 
            hexForm[i] = chr(temp + 48); 
            i = i + 1
        else : 
            hexForm[i] = chr(temp + 55); 
            i = i+1
    
    X = int(X/16); 

    j = i - 1; 
    while(j >= 0): 
        print((hexaDeciNum[j]), end = ""); 
        j = j - 1; 
"""
def decToHexa(n): 
      
    # char array to store  
    # hexadecimal number 
    hexaDeciNum = ['0'] * 100; 
      
    # counter for hexadecimal  
    # number array 
    i = 0; 
    while(n != 0): 
          
        # temporary variable  
        # to store remainder 
        temp = 0; 
          
        # storing remainder  
        # in temp variable. 
        temp = n % 16; 
          
        # check if temp < 10 
        if(temp < 10): 
            hexaDeciNum[i] = chr(temp + 48); 
            i = i + 1; 
        else: 
            hexaDeciNum[i] = chr(temp + 55); 
            i = i + 1; 
        n = int(n / 16); 
          
    # printing hexadecimal number 
    # array in reverse order 
    j = i - 1; 
    while(j >= 0): 
        print((hexaDeciNum[j]), end = ""); 
        j = j - 1; 
"""


print(decToHex(14))

