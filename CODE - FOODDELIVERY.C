#include<stdio.h>
#include<conio.h>
#define max 50
struct queue
{
  char cust_name[30], food[30],rest_name[20],pay[10],email[40],bldg[20],area[20];
  int flat_no;
};
struct queue q[max];
int f=-1,r=-1,n,i;
void order();
void deliver();
void next_order();
void view_orders();
int main()
{
  int ch;
  clrscr();
  printf("\t\t\t******FOODSTER DELIVERY******");
  printf("\n\n\t\tMAIN MENU");
  do
  {
    printf("\n\t1.Order Food\n\t2.Deliver Food\n\t3.View next order\n\t4.View Pending Orders\n\t5.Exit");
    printf("\n\tChoose action to be performed:");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1: order();
	      break;
      case 2: deliver();
	      break;
      case 3: next_order();
	      break;
      case 4: view_orders();
	      break;
      case 5: break;
      default : printf("\nInvalid action selected!\nTry again.\n");
    }
  }while(ch!=5);
  return 0;
}
void order()
{
  int temp;
  if((r+1)%max==f)
  {
    printf("\nCan't take order!\n");
  }
  else if(f==-1 && r==-1)
  {
    f=r=0;
  printf("\n\t\t****RESTAURANTS****");
  printf("\n->>Food Inn\t->>Delight\t->>Foodland\t->>Tea Villa\t->>Di Bella\t->>Food Junction");
  printf("\nRestaurant Name:\n");
  scanf("%c",&temp);
  scanf("%[^\n]",&q[r].rest_name);
  printf("\n\t\t****FOOD MENU****");
  printf("\n->>Breakfast:\tPancakes, Upma, Oatmeal, Dosa, FrenchToast,\n->>Lunch:\tPasta, Noodles, Soup, Chappati, Pulao\n->>Beverages:\tCold Drink, Tea, Coffee, Cocktail, Mojito\n->>Dessert:\tBrownie, Ice Cream, Waffle, Pastry\n->>Dinner:\tPav Bhaji, Paneer, Rice, Curry\n");
  printf("Enter food items and its quantity: (Fooodname/quantity)\n");
  scanf("%c",&temp);
  scanf("%[^\n]",q[r].food);
  printf("\n\t\t***ORDER SUMMARY***\n");
  printf("->Restaurant Name: %s",q[r].rest_name);
  printf("\n->Food: %s",q[r].food);
  printf("\n->Customer Name:");
  scanf("%c",&temp);
  scanf("%[^\n]",q[r].cust_name);
  printf("->Flat Number:");
  scanf("%d",&q[r].flat_no);
  printf("->Building Name:");
  scanf("%c",&temp);
  scanf("%[^\n]",q[r].bldg);
  printf("->Area & City:");
  scanf("%c",&temp);
  scanf("%[^\n]",q[r].area);
  printf("->Email ID:");
  scanf("%c",&temp);
  scanf("%[^\n]",q[r].email);
  printf("->Payment Mode:\nOnline\tOr\tCash on delivery\n");
  scanf("%c",&temp);
  scanf("%[^\n]",q[r].pay);
  printf("Order recieved successfully!\nTasty food will be enroute.\nThanks for ordering %s!\n",q[r].cust_name);
  }
  else
  {
    r=(r+1)%max;
    printf("\n\t\t****RESTAURANTS****");
    printf("\n->>Food Inn\t->>Delight\t->>Foodland\t->>Tea Villa\t->>Di Bella\t->>Food Junction");
    printf("\nRestaurant Name:\n");
    scanf("%c",&temp);
    scanf("%[^\n]",&q[r].rest_name);
    printf("\n\t\t****FOOD MENU****");
    printf("\n->>Breakfast:\tPancakes, Upma, Oatmeal, Dosa, FrenchToast,\n->>Lunch:\tPasta, Noodles, Soup, Chappati, Pulao\n->>Beverages:\tCold Drink, Tea, Coffee, Cocktail, Mojito\n->>Dessert:\tBrownie, Ice Cream, Waffle, Pastry\n->>Dinner:\tPav Bhaji, Paneer, Rice, Curry\n");
    printf("Enter food items and its quantity: (Fooodname/quantity)\n");
    scanf("%c",&temp);
    scanf("%[^\n]",q[r].food);
    printf("\n\t\t***ORDER SUMMARY***\n");
    printf("->Restaurant Name: %s",q[r].rest_name);
    printf("\n->Food: %s",q[r].food);
    printf("\n->Customer Name:");
    scanf("%c",&temp);
    scanf("%[^\n]",q[r].cust_name);
    printf("->Flat Number:");
    scanf("%d",&q[r].flat_no);
    printf("->Building Name:");
    scanf("%c",&temp);
    scanf("%[^\n]",q[r].bldg);
    printf("->Area & City:");
    scanf("%c",&temp);
    scanf("%[^\n]",q[r].area);
    printf("->Email ID:");
    scanf("%c",&temp);
    scanf("%[^\n]",q[r].email);
    printf("->Payment Mode:\nOnline\tOr\tCash on delivery\n");
    scanf("%c",&temp);
    scanf("%[^\n]",q[r].pay);
    printf("Order recieved successfully!\nTasty food will be enroute.\nThanks for ordering %s!\n",q[r].cust_name);
  }
}
void deliver()
{
   if(f==-1 && r==-1)
   {
     printf("\nNo orders for now.\n");
   }
   else
   {
      printf("\nOrder out for delivery to %s\n",q[f].cust_name);
      if(f==r)
      {
	f=r=-1;
      }
      else
      {
	 if(f==max-1)
	 {
	   f=0;
	 }
	 else
	 {
	   f++;
	 }
      }
   }
}
void next_order()
{
  if(f==-1 && r==-1)
  {
    printf("\nNo orders.\n");
  }
  else
  {
    printf("\n\t\t****ORDER****");
    printf("\nCustomer Name: %s",q[f].cust_name);
    printf("\nFood: %s",q[f].food);
    printf("\nRestaurant Name: %s",q[f].rest_name);
    printf("\nFlat Number: %d",q[f].flat_no);
    printf("\nBuilding Name: %s",q[f].bldg);
    printf("\nArea & City: %s",q[f].area);
    printf("\nEmail ID: %s",q[f].email);
    printf("\nPayment Mode: %s",q[f].pay);
    printf("\n");
  }
}
void view_orders()
{
   int i;
   if(f==-1 && r==-1)
   {
     printf("\nNo orders.\n");
   }
   else if(r<f)
   {
     printf("\nPending Orders Details:");
     for(i=0;i<=r;i++)
     {
	printf("\n\n\t\t****ORDER****");
	printf("\nCustomer Name: %s",q[i].cust_name);
	printf("\nFood: %s",q[i].food);
	printf("\nRestaurant Name: %s",q[i].rest_name);
	printf("\nFlat Number: %d",q[i].flat_no);
	printf("\nBuilding Name: %s",q[i].bldg);
	printf("\nArea & City: %s",q[i].area);
	printf("\nEmail ID: %s",q[i].email);
	printf("\nPayment Mode: %s",q[i].pay);
     }
     for(i=f;i<max;i++)
     {
	printf("\n\n\t\t****ORDER****");
	printf("\nCustomer Name: %s",q[i].cust_name);
	printf("\nFood: %s",q[i].food);
	printf("\nRestaurant Name: %s",q[i].rest_name);
	printf("\nFlat Number: %d",q[i].flat_no);
	printf("\nBuilding Name: %s",q[i].bldg);
	printf("\nArea & City: %s",q[i].area);
	printf("\nEmail ID: %s",q[i].email);
	printf("\nPayment Mode: %s",q[i].pay);
	printf("\n");
     }
   }
   else
   {
      printf("\nPending Orders Details:");
      for(i=f;i<=r;i++)
      {
	printf("\n\n\t\t****ORDER****");
	printf("\nCustomer Name: %s",q[i].cust_name);
	printf("\nFood: %s",q[i].food);
	printf("\nRestaurant Name: %s",q[i].rest_name);
	printf("\nFlat Number: %d",q[i].flat_no);
	printf("\nBuilding Name: %s",q[i].bldg);
	printf("\nArea & City: %s",q[i].area);
	printf("\nEmail ID: %s",q[i].email);
	printf("\nPayment Mode: %s",q[i].pay);
	printf("\n");
      }
   }
}


