#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_pm 10
#define max_gld 15
#define max_slv 15
#define max_gnl 20

int seat_number_pm = 0, seat_number_gld = 0, seat_number_slv = 0, seat_number_gnl = 0;
int price_pm, price_gld, price_slv, price_gnl;
char premium[10][10], gold[15][10], silver[15][10], general[20][10];

struct movie_seat
{
    char name[10];
    char types[15];
    int seat_number;
    float price;
    struct movie_seat *link;
};

typedef struct movie_seat snode;
snode *start = NULL;

float calculate_price(float price)
{
    if (price > 100)
        return price + (18 * price) / 100;
    else
        return price + (12 * price) / 100;
}

snode *book_seat(float price, int seat_no, char type[])
{
    snode *ns;
    ns = (snode *)malloc(sizeof(snode));
    printf("\nName: ");
    scanf("%s", ns->name);
    strcpy(ns->types, type);
    ns->seat_number = seat_no;
    ns->price = calculate_price(price);
    ns->link = NULL;
    printf("Your seat number is %d\n", ns->seat_number);
    printf("Pay Rs.%f to book your seat\n\n", ns->price);
    return ns;
}


void update_list(int seat_no, char type[], char name[])
{
    if (strcmp(type, "Premium") == 0)
        strcpy(premium[seat_no - 1], name);
    else if (!strcmp(type, "Gold"))
        strcpy(gold[seat_no - 1], name);
    else if (!strcmp(type, "Silver"))
        strcpy(silver[seat_no - 1], name);
    else if (!strcmp(type, "General"))
        strcpy(general[seat_no - 1], name);
}

void insert_node(float price, int seat_no, char type[])
{
    snode *newnode, *temp;
    newnode = book_seat(price, seat_no, type);
    if (start == NULL)
        start = newnode;
    else
    {
        temp = start;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
    update_list(seat_no, type, newnode->name);
}

int bookAvailable(float price, char type[])
{
    snode *temp, *nn, *prev;
    temp = start;
    while (temp != NULL)
    {
        if (!strcmp(temp->name, "available") && !strcmp(temp->types, type))
            break;
        prev=temp;
        temp = temp->link;
    }

    if (temp == NULL)
        return 0;
    nn = book_seat(price, temp->seat_number, type);
    if(temp==start)
    {
        start=nn;
        nn->link=temp->link;
    }       
    else
    {
        prev->link=nn;
        nn->link=temp->link;
    }
    update_list(nn->seat_number, type, nn->name);
    return 1;
}

void bookTicket()
{
    int num, type, press, i;
    do
    {
        printf("\nHow much ticket you wanna buy: ");
        scanf("%d", &num);
        printf("Which class? \n1. Premium\n2. Gold\n3. Silver\n4. General\n");
        scanf("%d", &type);

        for (i = 0; i < num; i++)
        {
            switch (type)
            {
            case 1:
                if (bookAvailable(price_pm, "Premium") == 1)
                    break;
                if (seat_number_pm == max_pm)
                    goto next;
                seat_number_pm = seat_number_pm + 1;
                insert_node(price_pm, seat_number_pm, "Premium");
                break;
            case 2:
                if (bookAvailable(price_gld, "Gold") == 1)
                    break;
                if (seat_number_gld == max_gld)
                    goto next;
                seat_number_gld = seat_number_gld + 1;
                insert_node(price_gld, seat_number_gld, "Gold");
                break;
            case 3:
                if (bookAvailable(price_slv, "Silver") == 1)
                    break;
                if (seat_number_slv == max_slv)
                    goto next;
                seat_number_slv = seat_number_slv + 1;
                insert_node(price_slv, seat_number_slv, "Silver");
                break;
            case 4:
                if (bookAvailable(price_gnl, "General") == 1)
                    break;
                if (seat_number_gnl == max_gnl)
                    goto next;
                seat_number_gnl = seat_number_gnl + 1;
                insert_node(price_gnl, seat_number_gnl, "General");
                break;
            }
        }
        goto buy;
    next:
        printf("Sorry....All seat in this class filled !\n");
        printf("Try with another class \n\n");
    buy:
        printf("Do you want more tickets: (if yes press 1): ");
        scanf("%d", &press);
    } while (press == 1);

    printf("\n----------- THANK YOU -----------\n\n\n");
}

void cancel_book(char type[])
{
    int n;
    printf("Enter seat number: ");
    scanf("%d", &n);
    snode *temp = start;
    while (temp != NULL)
    {
        if (temp->seat_number == n && strcmp(temp->types, type) == 0)
            break;
        temp = temp->link;
    }

    if (temp == NULL)
        printf("\nInvalid seat\n");
    else
    {
        printf("\n%s`s seat cancelled succesfully\n", temp->name);
        strcpy(temp->name, "available");
        update_list(n, type, "available");
    }
}

void display_details()
{
    int i;
    snode *temp=start;
    while (temp != NULL)
    {
        if(strcmp(temp->name, "available"))
            break;
        temp = temp->link;
    }
    if(temp==NULL)
    {
        printf("No seats are booked...!");
        return;
	}

    printf("\n\n-------Premium Class-------\n\n");
    printf("Seat no.\tname\n");
    for (i = 0; i < seat_number_pm; i++)
    {
        printf("  %d\t\t %s\n", i + 1, premium[i]);
    }
    printf("\n-------Gold Class-------\n\n");
    printf("Seat no.\tname\n");
    for (i = 0; i < seat_number_gld; i++)
    {
        printf("  %d\t\t %s\n", i + 1, gold[i]);
    }
    printf("\n-------Silver Class-------\n\n");
    printf("Seat no.\tname\n");
    for (i = 0; i < seat_number_slv; i++)
    {
        printf("  %d\t\t %s\n", i + 1, silver[i]);
    }
    printf("\n-------General Class-------\n\n");
    printf("Seat no.\tname\n");
    for (i = 0; i < seat_number_gnl; i++)
    {
        printf("  %d\t\t %s\n", i + 1, general[i]);
    }
}

void search(char names[])
{
    int found = 0;
    snode *temp = start;
    while (temp != NULL)
    {
        if (strcmp(names, temp->name) == 0)
        {
            printf("\n%s booked seat in %s\n", temp->name, temp->types);
            printf("His seat number is %d\n\n", temp->seat_number);
            found = 1;
        }
        temp = temp->link;
    }
    if (found == 0)
    {
        printf("\nNo result found...\n");
    }
}

int main()
{
    char name[10];
    int choice, type;

    printf("------- Enter Ticket price -------\n\n");
    printf("Premium class -- ");
    scanf("%d", &price_pm);
    printf("Gold class -- ");
    scanf("%d", &price_gld);
    printf("Silver class -- ");
    scanf("%d", &price_slv);
    printf("General class -- ");
    scanf("%d", &price_gnl);
    printf("\n----------------------------------\n\n");

    bookTicket();

    printf("----------- Booking Details ------------\n\n");
    while (1)
    {
        printf("\nPress 1 to search for a specific person\nPress 2 to have each seat details\n");
        printf("Press 3 to cancel your booking\nPress 4 to book more tickets\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter name you want to search: ");
            scanf("%s", name);
            search(name);
            break;
        case 2:
            display_details();
            break;
        case 3:
            printf("Which class? \n1. Premium\n2. Gold\n3. Silver\n4. General\n");
            scanf("%d", &type);
            if (type == 1)
                cancel_book("Premium");
            else if (type == 2)
                cancel_book("Gold");
            else if (type == 3)
                cancel_book("Silver");
            else if (type == 4)
                cancel_book("General");
            break;
        case 4:
            bookTicket();
            break;
        default:
            return 0;
        }
    }
}
