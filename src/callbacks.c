#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include"string.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
int check(char );
char x[100];
int i=0;
extern  GtkWidget *window1;
	 GtkWidget *t1;
void
on_clear_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	i=0;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}
void
on_bksp_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	i--;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
	
}


void
on_ce_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	i=0;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_pm_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_seven_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='7';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);
}


void
on_six_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='6';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_nine_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='9';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_div_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='/';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_four_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='4';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_five_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='5';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_mul_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='*';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_one_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='1';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_two_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='2';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_three_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='3';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_minus_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='-';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_zero_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='0';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_dot_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='.';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}


void
on_equal_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	char opr[20],opd[20];
	char s[20];
	int i,j=-1,k=-1;
	int a,b,c;
	for(i=0;i<strlen(x);i++)
	{
		if(x[i]>=48 && x[i]<=57)
		{
		j++;
		opd[j]=x[i];
		}
		else
		{
			if(k==-1)
			{
			k++;
			opr[k]=x[i];
			}
			else	
			{
				a=check(x[i]);
				b=check(opr[k]);
				while(k>=0 && a<=b)
				{
					j++;
					opd[j]=opr[k];
					k--;
				if(k==-1)
					break;
				b=check(opr[k]);				
				}
				k++;
				opr[k]=x[i];
			}
		}
		
	}
	while(k>=0)
	{
		j++;
		opd[j]=opr[k];
		k--;
	}
	 int l=-1;
	int m,n,o;
	for(i=0;i<strlen(opd);i++)
	{
		if(opd[i]>=48 && opd[i]<=57)
		{
			l++;
			s[l]=opd[i]-48;
		}
		else
		{
			o=s[l];
			l--;
			n=s[l];
			l--;
			if(opd[i]=='-')
				m=n-o;	
			else
			if(opd[i]=='+')
				m=n+o;
			else
			if(opd[i]=='/')
				m=n/o;
			else if(opd[i]=='*')
				m=n*o;
			l++;
			s[l]=m;
		}
	}
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	i=0;
	sprintf(x,"%d",s[l]);
	gtk_entry_set_text(t1,x);
}
int check(char m)
{
	switch(m)
	{
		case '+':
		case '-':
			return 5;
		case '/':
		case '*':
		case '%':
			return 6;
			
	}
}


void
on_plus_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='+';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}

void
on_eight_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	t1=lookup_widget(GTK_WIDGET(button),"entry1");
	x[i]='8';
	i++;
	x[i]='\0';
	gtk_entry_set_text(t1,x);

}

