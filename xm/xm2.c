/*
 * To compile:
 * gcc -o xm2 xm2.c -lXm -lXt -lXext -lX11 -lm
*/

#include <Xm/Xm.h> 
#include <Xm/PushB.h>
#include <stdio.h> 

/* Prototype Callback function */

void main(int argc, char** argv);
void pushed_fn(Widget , XtPointer , XtPointer);


void main(int argc, char** argv) 

{   Widget top_wid, button;
    XtAppContext  app;
   
    top_wid = XtVaAppInitialize(&app, "Push", NULL, 0,
        &argc, argv, NULL, NULL);

    button = XmCreatePushButton(top_wid, "Push_me", NULL, 0);

    /* tell Xt to manage button */
				XtManageChild(button);
   
				/* attach fn to widget */
    XtAddCallback(button, XmNactivateCallback, pushed_fn, NULL);

    XtRealizeWidget(top_wid); /* display widget hierarchy */
    XtAppMainLoop(app); /* enter processing loop */ 

}

void pushed_fn(Widget w, XtPointer client_data, XtPointer cbsXt) 
{   
    XmPushButtonCallbackStruct *cbs = (XmPushButtonCallbackStruct*)cbsXt;

     printf("Don't Push Me!!\n");
}
