#include <iostream> 
#include <vector>   
#include <string>  
#include "../MerkelMain/MerkelMain.h" // Include the MerkelMain.h header file from the "MerkelMain" directory.

int main(void)
{
    MerkelMain app{}; // Create an instance of the MerkelMain class.

    app.init();       // Call the "init" method of the MerkelMain class.
                      // This method is responsible for initializing the application.
    return 0;
}



