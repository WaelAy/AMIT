#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

/******************************************/
/**** Column , Row Must not exceed 4x4 ****/
/******************************************/
#define KEYPAD_ROW_NUM              4
#define KEYPAD_COL_NUM              4

/******************************************/
/****  Column , Row Pin Configuration  ****/
/******************************************/
#define R1_PORT     'D'          
#define R1_PIN       0       

#define R2_PORT     'D'       
#define R2_PIN       1      

#define R3_PORT     'D'       
#define R3_PIN       2        

#define R4_PORT      'D'       
#define R4_PIN        3    



#define C1_PORT       'D'      
#define C1_PIN         4     

#define C2_PORT        'D'    
#define C2_PIN          5  

#define C3_PORT         'D'    
#define C3_PIN           6  

#define C4_PORT          'D'  
#define C4_PIN            7 

/******************************************/
/****           Key Values             ****/
/******************************************/

#define KEYPAD_KEY_VALUES           {\
                                        {'7','8','9','/'},\
                                        {'4','5','6','x'},\
                                        {'1','2','3','-'},\
                                        {'C','0','=','+'},\
                                    }

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
