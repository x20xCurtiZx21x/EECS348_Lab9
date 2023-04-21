/*
 * Program1.c
 *
 *  Created on: Feb 10, 2023
 *  Last Revised Feb 11, 2023
 *      Author: c950c102
 */
#include <stdio.h>

#include <stdlib.h>

char* monthName;

char userFile[100]="";

FILE *textfile;

char line[12];

int sortedMonth[12];

float sales[12];

float temp[12];

int num;

int num2;

int maxMonth;

int minMonth;

float max;

float min;

float sum;

float calcAverage(int numStart, int numEnd){

	sum = 0;

	for (int i=numStart; i <= numEnd; i++){

		sum = sum + sales[i];
	}

	sum = sum / (numEnd - numStart + 1);

	return sum;
}

char* declareMonth(int num){

	if (num == 0){
		return "January";
	} else if (num == 1){
		return "February";
	} else if (num == 2){
		return "March";
	} else if (num == 3){
		return "April";
	} else if (num == 4){
		return "May";
	} else if (num == 5){
		return "June";
	} else if (num == 6){
		return "July";
	} else if (num == 7){
		return "August";
	} else if (num == 8){
		return "September";
	} else if (num == 9){
		return "October";
	} else if (num == 10){
		return "November";
	} else{
		return "December";
	}
}

float maxValue(){

	num = 1;

	maxMonth = 0;

	max = sales[0];

	while (num<=11){

		if (max < sales[num]){

			max = sales[num];

			maxMonth = num;
		}

		num++;
	}

	return maxMonth;
}

float minValue(){

	num = 1;

	minMonth = 0;

	min = sales[0];

	while (num<=11){

		if (min > sales[num]){

			min = sales[num];

			minMonth = num;
		}

		num++;
	}

	return minMonth;
}

int sortMonths(){

	int currmax;

	num = 0;

	while (num <= 11){

		num2 = 1;

		currmax = 0;

		max = temp[0];

		while (num2<=11){

			if (max < temp[num2]){

				max = temp[num2];

				currmax = num2;
			}

			num2++;
		}

		temp[currmax] = -1;

		sortedMonth[num] = currmax;

		num++;
	}
	return 0;
}

int main(){

	int userInput;

	printf("%s","Would you like to read a file(1) or input manually(2)?\n");

	scanf("%d", &userInput);

	if (userInput == 1){

		printf("%s","Enter your input file(Make sure you add the extension):\n");

		scanf("%s", &userFile);

		textfile = fopen(userFile, "r");

		num = 0;

		while (fgets(line, 12, textfile)){

			sales[num] = atof(line);

			num++;
		}

		fclose(textfile);

	}else{

		printf("%s", "Enter your sales for each month (spaced out and in order):\n");

		scanf("%f %f %f %f %f %f %f %f %f %f %f %f", &sales[0], &sales[1], &sales[2], &sales[3], &sales[4], &sales[5], &sales[6], &sales[7], &sales[8], &sales[9], &sales[10], &sales[11]);
	}

	for (int i = 0; i <= 11; i++){

		temp[i] = sales[i];
	}

	printf("%s", "\nMonthly Sales report for 2022:\n\n");

	printf("%s","Month   \tSales\n\n");

	num = 0;

	while (num<=11){

		monthName = declareMonth(num);

		printf("%s     \t$%f\n", monthName, sales[num]);

		num++;
	}

	maxMonth = maxValue();

	minMonth = minValue();

	printf("%s", "\nSales Summary:\n\n");

	printf("%s\t$%f\t(%s)\n", "Minimum Sales:", sales[minMonth], declareMonth(minMonth));

	printf("%s\t$%f\t(%s)\n","Maximum Sales:", sales[maxMonth], declareMonth(maxMonth));

	printf("%s\t$%f\n\n","Average Sales:", calcAverage(0, 11));

	printf("%s\n\n","Six Month Average Report:");

	printf("%s\t\t$%f\n","January\t - June",calcAverage(0, 5));

	printf("%s\t\t$%f\n","February - July",calcAverage(1, 6));

	printf("%s\t$%f\n","March\t - August",calcAverage(2, 7));

	printf("%s\t$%f\n","April\t - September",calcAverage(3, 8));

	printf("%s\t$%f\n","May\t - October",calcAverage(4, 9));

	printf("%s\t$%f\n","June\t - November",calcAverage(5, 10));

	printf("%s\t$%f\n\n","July\t - December",calcAverage(6, 11));

	sortMonths();

	printf("%s", "Sales Report(Highest to Lowest):\n\n");

	printf("%s","Month   \tSales\n\n");

	num = 0;

	while (num<=11) {

		num2 = sortedMonth[num];

		monthName = declareMonth(num2);

		printf("%s     \t$%f\n", monthName, sales[num2]);

		num++;
	}

	return 0;
}