logic()
{
	lr_start_transaction("enter");
	
	vuser_init();
	
	lr_end_transaction("enter");
	lr_think_time(4);
	
	lr_start_transaction("createTicket");
	
	createTicket();
	
	lr_end_transaction("createTicket");
	lr_think_time(4);
	
	lr_start_transaction("toItinerary");
	
	toItinerary();
	
	lr_end_transaction("toItinerary");
	lr_think_time(4);
	
	lr_start_transaction("exit");
	
	vuser_end();
	
	lr_end_transaction("exit");
	lr_think_time(4);
	
	return 0;
}
