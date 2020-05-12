    /**
	Code Author: Utsavi Visaria, rishabh kothari , aayushi waghela 
	Guided By: Vaibhav Vasani
	College: K J Somaiya College of Engineering
	Date of Submission: 01-05-2020
	*/
	#include<stdio.h> 
	void selectpuzzle(); 
	int checkrows();
	int checkcolumns(); 
	int checkboxes();
	int a[16][16];
	void main() 
	{
	int i,j,r,c,f,g,h,m=186,n=205,o=206,x=1,b[16][16]; 
	 selectpuzzle();
	 for(i=0;i<16;i++)
	 {
	  for(j=0;j<16;j++)//Meant to store positions of fixed numbers  
	  {
	    if(a[i][j]==0)
	        b[i][j]=0; 
	     else b[i][j]=1;
	} }
	while(x==1) 
	{
	for(i=0;i<16;i++)//Displaying the sudoku puzzle 
	{
	if(i==0) 
	{
	printf(" "); 
	    for(j=1;j<=16;j++) 
	    {
	if(j%4==1)
	    printf(" %2d ",j); 
	        else
	printf("%2d ",j); 
	    }
	printf("\n\n"); 
	}
	printf("%2d ",i+1); 
	    for(j=0;j<16;j++)
	{
	printf("%2d ",a[i][j]); 
	        if(j==3 || j==7 || j==11) 
	            printf("%c",m);
	}
	printf("\n");
	if(i==3 || i==7 || i==11) 
	{
	printf(" ");
	    for(j=0;j<19;j++) 
	    {
	if(j==4) 
	    printf("%3c %c",o,n); 
	     else if(j==8)
	       printf("%2c %c",o,n);
	     else if(j==12)
	       printf("%2c %c",o,n);
	     else printf("%c %c",n,n);
	}
	    printf("\n");
	} 
	}
	for(;;)//Conditions for solving a sudoku
	{
	 printf("Enter row number:"); 
	    scanf("%2d",&r);
	printf("Enter column number:"); 
	    scanf("%2d",&c);
	if(r<1 || r>16 || c<1 ||c>16) 
	{
	printf("Invalid choice please enter again."); 
	    continue;
	}
	r--;
	c--; 
	    if(b[r][c]==0)
	        break;
	else
	printf("Fixed position. Enter again.\n"); 
	}
	for(;;)
	{
	printf("Enter number from 1 to 16:");
	    scanf("%d",&a[r][c]);
	if(a[r][c]<1 || a[r][c]>16)
	printf("Invalid input. Please enter again."); 
	    else
	break;
	}
	printf("Enter 1 to continue solving:"); 
	scanf("%d",&x);
	}
	for(i=0;i<16;i++)
	{
	if(i==0) 
	{
	printf(" "); 
	    for(j=1;j<=16;j++)
	    {
	if(j%4==1) 
	    printf(" %2d ",j); 
	        else
	printf("%2d ",j);
	    }
	printf("\n\n"); 
	}
	printf("%2d ",i+1); 
	    for(j=0;j<16;j++)
	{
	printf("%2d ",a[i][j]); 
	        if(j==3 || j==7 || j==11) 
	            printf("%c ",m);
	}
	printf("\n");
	if(i==3 || i==7 || j==11) 
	{
	printf(" "); 
	    for(j=0;j<19;j++)
	    {
	if(j==4 || j==8 || j==12) 
	    printf("%c%c",o,n);
	

	 else printf("%c%c",n,n);
	    }
	printf("\n"); 
	

	}
	}
	f=checkrows(); 
	g=checkcolumns();
	h=checkboxes(); 
	if(f==0 || g==0 || h==0) 
	{
	printf("Sudoku incorrectly solved."); 
	}
	else 
	{
	printf("Sudoku correctly solved.");
	}
	}
	void selectpuzzle()
	{
	int ch,i,j;
	int a1[16][16]={{01,00,00,02,03,04,00,00,12,00,06,00,00,00,07,00}, {00,00, 8,00,00,00,07,00,00,03,00,00, 9,10,06,11}, {00,12,00,00,10,00,00,01,00,13,00,11,00,00,14,00}, {03,00,00,15,02,00,00,14,00,00,00, 9,00,00,12,00}, {13,00,00,00, 8,00,00,10,00,12,02,00,01,15,00,00}, {00,11,07,06,00,00,00,16,00,00,00,15,00,00,05,13}, {00,00,00,10,00,05,15,00,00,04,00, 8,00,00,11,00}, {16,00,00,05, 9,12,00,00,01,00,00,00,00,00, 8,00}, {00,02,00,00,00,00,00,13,00,00,12,05, 8,00,00,03}, {00,13,00,00,15,00,03,00,00,14, 8,00,16,00,00,00}, {05, 8,00,00,01,00,00,00,02,00,00,00,13, 9,15,00}, {00,00,12,04,00,06,16,00,13,00,00,07,00,00,00,05}, {00,03,00,00,12,00,00,00,06,00,00,04,11,00,00,16}, {00,07,00,00,16,00,05,00,14,00,00,01,00,00,02,00}, {11,01,15, 9,00,00,13,00,00,02,00,00,00,14,00,00}, {00,14,00,00,00,11,00,02,00,00,13,03,05,00,00,12}};
	int a2[16][16]={{0,0,0,0,0,0,0,0,2,5,0,12,0,4,3,7}, {0,8,0,0,7,0,0,0,3,16,0,0,6,0,0,0}, {3,0,0,0,14,0,6,0,0,0,15,0,0,5,0,9}, {0,7,11,5,4,13,0,0,0,0,1,14,0,0,10,0}, {2,13,1,8,9,0,0,0,14,0,6,0,0,0,0,0}, {10,3,4,0,5,0,15,0,0,0,16,0,0,11,6,2}, {0,0,14,15,1,6,0,0,7,0,2,3,0,12,8,10}, {0,0,16,6,2,0,0,0,11,15,0,0,0,0,0,14}, {13,0,0,0,0,0,14,15,0,0,0,10,4,8,0,0}, {15,6,8,0,10,5,0,16,0,0,12,1,2,9,0,0}, {7,11,5,0,0,1,0,0,0,8,0,2,0,10,12,3}, {0,0,0,0,0,9,0,8,0,0,0,11,1,13,15,5}, {0,16,0,0,12,3,0,0,0,0,4,6,10,2,11,0}, {5,0,6,0,0,14,0,0,0,1,7,0,0,0,4}, {0,0,0,1,0,0,11,9,0,0,0,16,0,0,13,0}, {8,2,10,0,16,0,5,7,0,0,0,0,0,0,0,0}};
	int a3[16][16]={{11,0,5,0,0,12,0,0,13,0,0,10,0,0,0,0}, {0,13,0,0,0,0,5,0,1,0,14,0,2,0,0,0}, {0,0,0,9,0,0,0,2,0,5,0,0,14,0,7,0}, {4,0,12,0,8,0,0,0,0,0,0,16,0,10,0,0}, {0,9,0,11,0,0,4,0,3,6,0,0,0,0,0,7},{6,0,8,0,10,13,0,16,0,0,11,0,15,0,9,0}, {0,3,0,0,0,0,2,0,15,0,0,0,0,13,0,1}, {16,0,0,2,0,1,0,5,0,14,0,8,0,0,0,0}, {0,0,16,0,13,4,0,0,0,0,0,0,0,0,12,0}, {0,0,10,3,0,7,0,0,5,0,16,0,9,0,0,15}, {15,0,11,0,1,0,0,9,0,2,0,3,0,4,0,0}, {0,0,0,0,0,0,8,0,0,0,4,0,10,0,0,0}, {2,0,4,0,0,0,0,0,0,0,0,12,0,0,5,0}, {0,12,0,13,0,0,0,1,0,0,10,0,0,3,0,8}, {8,0,9,0,4,0,3,0,0,7,0,0,11,0,13,0}, {0,5,0,14,0,0,0,11,0,0,1,6,0,0,0,10}};
	for(;;) 
	{
	printf("Enter 1, 2 or 3 to select respective puzzle:"); 
	    scanf("%d",&ch);
	if(ch<=3 && ch>=1)
	break;
	else
	printf("Invalid choice."); 
	}
	switch(ch)
	{
	case 1: for(i=0;i<16;i++) 
	{
	for(j=0;j<16;j++)
	{
	a[i][j]=a1[i][j]; 
	}
	}
	break;
	case 2: 
	        for(i=0;i<16;i++) 
	        {
	for(j=0;j<16;j++)
	{
	a[i][j]=a2[i][j];
	}
	}
	break;
	case 3: 
	        for(i=0;i<16;i++)
	        {
	for(j=0;j<16;j++)
	{
	a[i][j]=a3[i][j];
	}
	} 
	        break;
	} }
	int checkrows()
	{
	int i,j,k,x; 
	for(i=0;i<16;i++) 
	{
	for(j=1;j<=16;j++)
	{
	

	x=0;
	    for(k=0;k<16;k++) 
	{
	if(a[i][k]==j)
	    x++;
	}
	if(x!=1)
	    return 0; 
	}
	    
	}
	return 1; 
	}
	int checkcolumns() 
	{
	int i,j,k,x; 
	    for(i=0;i<16;i++) 
	    {
	for(j=1;j<=16;j++)
	{
	x=0; 
	    for(k=0;k<16;k++)
	    {
	if(a[k][i]==j)
	    x++;
	}
	if(x!=1) 
	    return 0; 
	}
	}
	return 1; 
	}
	int checkboxes() 
	{
	int i,j,k,l,m,x; 
	    for(i=0;i<16;i+=4)
	{
	for(j=0;j<16;j+=4)
	{
	for(k=1;k<=16;k++) 
	{
	x=0;
	    for(l=i;l<i+4;l++)
	    {
	for(m=j;m<j+4;m++) 
	{
	if(a[l][m]==k)
	    x++;
	}
	}
	if(x!=1)
	    return 0;
	}
	}
	}
	return 1;
	}

