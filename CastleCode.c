#pragma config(Sensor, in1,    Castle1point1,  sensorLineFollower)
#pragma config(Sensor, in2,    Castle1point2,  sensorLineFollower)
#pragma config(Sensor, in3,    Castle1point3,  sensorLineFollower)
#pragma config(Sensor, in4,    Castle1king,    sensorReflection)
#pragma config(Sensor, dgtl1,  startbutton,    sensorTouch)
#pragma config(Sensor, dgtl2,  stopbutton,     sensorTouch)
#pragma config(Sensor, dgtl6,  castle2LED1,    sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  castle2LED2,    sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  castle2LED3,    sensorLEDtoVCC)
#pragma config(Motor,  port2,           servo1king,    tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//                                                                                                                                           
//     #####                    #####  # ###   ###                   /                        #####                                          
//  ######                   ######  /    ###   ###                #/                      ######                #                           
// /#   /  /    ##          /#   /  /      ##    ##          #     ##                     /#   /  /    ##       ###                          
///    /  /   #### /       /    /  /       ##    ##         ##     ##                    /    /  /   #### /      #                           
//    /  /     /##/            /  /        ##    ##         ##     ##                        /  /     /##/                                   
//   ## ##    / ##            ## ##        ##    ##       ######## ##  /##      /##         ## ##    / ##      ###   ###  /###     /###      
//   ## ##   /                ## ##        ##    ##      ########  ## / ###    / ###        ## ##   /           ###   ###/ #### / /  ###  /  
//   ## ####/               /### ##        ##    ##         ##     ##/   ###  /   ###       ## ####/             ##    ##   ###/ /    ###/   
//   ## ## ###             / ### ##        ##    ##         ##     ##     ## ##    ###      ## ## ###            ##    ##    ## ##     ##    
//   ## ##   ###              ## ##        ##    ##         ##     ##     ## ########       ## ##   ###          ##    ##    ## ##     ##    
//   #  ##    ###        ##   ## ##        ##    ##         ##     ##     ## #######        #  ##    ###         ##    ##    ## ##     ##    
//      /       ###     ###   #  /         ##    ##         ##     ##     ## ##                /       ###       ##    ##    ## ##     ##    
//  /##/         ###     ###    /          ##    ##         ##     ##     ## ####    /     /##/         ###      ##    ##    ## ##     ##    
// /  #####        ###  / #####/           ### / ### /      ##     ##     ##  ######/     /  #####        ###  / ### / ###   ### ########    
///    ###           ##/    ###             ##/   ##/        ##     ##    ##   #####     /    ###           ##/   ##/   ###   ###  ### ###   
//#                                                                       /              #                                              ###  
// ##                                                                    /                ##                                      ####   ### 
//                                                                      /                                                       /######  /#  
//                                                                     /                                                       /     ###/    
//


int castle_score1;
int vstart;
int castle;

task main()
{
	while(true)
	{
		if(SensorValue(startbutton) == 1)//If the start button is pressed
		{
			vstart = 1; //Change the variable start to 1
			clearTimer(T1); //clearTimer(Castle1Timer); //Clear the 1st castle timer
	
			castle_score1 = 0; //Set castle_score1 to 0
			while(vstart == 1) //While the variable start is equal to 1
			{
				if (SensorValue(Castle1point1) < 2900) //If the limit switch1 is pressed (over the 1st wall)
				{
					castle_score1 += 1; 	//Add one to the score
					turnLEDOn(castle2LED1); //Turn on the 1st LED for 2 seconds
					wait(2); 		//for 2 seconds
					turnLEDOff(castle2LED1);
				}

				if (SensorValue(Castle1point2) < 2900) //If the limit switch1 is pressed (over the 2nd wall)
				{
					castle_score1 += 2; 	//Add two to the score
					turnLEDOn(castle2LED2); //Turn on the 2nd LED for 2 seconds
					wait(1); 		//for 2 seconds
					turnLEDOff(castle2LED2);
				}

				if (SensorValue(Castle1point3) < 2900) //If the limit switch1 is pressed (over the 3rd wall)
				{
					castle_score1 += 3; 	//Add three to the score
					turnLEDOn(castle2LED3); //Turn on the 3rd LED
					wait(1); 		//for 2 seconds
					turnLEDOff(castle2LED3);
				}
				if (SensorValue(Castle1king)<170)
				{
					time1 = Timer[T1]; //time1 = Time[T1];
					setServo(servo1king, 90); //moves the flag
					castle = 2;
					vstart = 0;
				}
				
				if (SensorValue(stopbutton)== 1)
				{
					vstart = 0;
				}
			}
			/*
			if (castle == 1)
			{
			turnLEDOn(castle1LED1);
			turnLEDOn(castle1LED2);
			turnLEDOn(castle1LED3);
			wait(2);
			turnLEDOff(castle1LED1);
			turnLEDOff(castle1LED2);
			turnLEDOff(castle1LED3);
			}
			*/
			if (castle == 2)
			{
				turnLEDOn(castle2LED1);
				turnLEDOn(castle2LED2);
				turnLEDOn(castle2LED3);
				wait(2);
				turnLEDOff(castle2LED1);
				turnLEDOff(castle2LED2);
				turnLEDOff(castle2LED3);
			}
		}
	}
}
