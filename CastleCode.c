
task main()
{
	if (SensorValue(startbutton) = 1)//If the start button is pressed
	{
		startvariable = 1; //Change the variable start to 1
		while(startvariable = 1) //While the variable start is equal to 1
		{
			clearTimer(Castle1Timer); //Clear the 1st castle timer
			clearTimer(Castle2Timer); //Clear the 2nd Castle timer
			castle_score1 = 0; //Set castle_score1 to 0
			castle_score2 = 0; //Set castle_score2 to 0
		}
		if (SensorValue(Castle1point1) = 1) //If the limit switch1 is pressed (over the 1st wall)
		{
			castle_score2 = castle_score2 + 1; 	//Add one to the score
			turnLEDOn(castle1LED1); //Turn on the 1st LED for 2 seconds
		}
	}

	//If the 2nd limit switch is pressed (over the 2nd wall)
	//Add 2 to the score
	//Turn on GREENLED1 for 2 seconds

	//If the limit switch 3 is pressed (top moat in castle 1)
	//Add 3 to score1
	//Flash GREENLED2 light once

	//If the 1st light sensor value is darker than previous (1st King hit off)
	//Turn on all lights and flash them
	//Set the first castle servo to 90 so the flag is raised
	//Get the time for the First castle
	//If the time1 > time_king
	//Set time_king = time1

	//If the limit switch4 is pressed (Inside the 2nd castle moat)
	//Add one to the score2
	//Turn on the yellow light for 2 seconds

	//If the 5th limit switch is pressed
	//Turn on the Green LED for 2 seconds
	//Add two to the score2

	//If the limit switch 6 is pressed (top moat in castle2)
	//Add 3 to score 2
	//Flash some green light once

	//If the 2nd light sensor reads a value darker than before (2nd King is hit out)
	//Turn on all lights in the second castle and flash them
	//Set the 2nd Servo to 90 so the flag is raised
	//Get the time for the second castle
	//If the time2 > time_king
	//Set time_king = time2

	//If time 1 OR time 2 > 1 min
	//Turn on all lights
	//Record the score of castle 1 and 2
	//If the castle_score1 > high score AND castle_score1> castle_score 2
	//Set castle_score1 = high_score
	//If the castle_score2 > high score AND castle_score2> castle_score 1
	//Set castle_score2 = high_score

	//If the stop button is pressed
	//Set start to 0



}
