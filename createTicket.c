createTicket()
{
	tName = "03.Choice_City";
	lr_start_transaction(tName);
	
//	int randomNumber = rand()%2;

	status = web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	end_transaction(tName, status);
	lr_think_time(4);

//	lr_save_string(lr_eval_string("{city}"),"city1");
//	lr_output_message(lr_eval_string("{city1}"));
//	lr_save_string(lr_eval_string("{city}"),"city2");
//	lr_output_message(lr_eval_string("{city2}"));
//	lr_output_message(lr_eval_string("{seatPref}"));
//	lr_output_message(lr_eval_string("{seatType}"));
	
//	if (randomNumber == 0) {
		tName = "04.Choice_Flight";
		lr_start_transaction(tName);
		
		web_reg_save_param_ex(
		    "ParamName=outFlight", 
		    "LB/IC=name=\"outboundFlight\" value=\"",
		    "RB/IC=\"",
		    "Ordinal=all");
		
		status = web_submit_data("reservations.pl", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=depart", "Value={city}", ENDITEM, 
			"Name=departDate", "Value={date1}", ENDITEM, 
			"Name=arrive", "Value={city}", ENDITEM, 
			"Name=returnDate", "Value={date2}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=roundtrip", "Value=<OFF>", ENDITEM, 
			"Name=seatPref", "Value={seatPref}", ENDITEM, 
			"Name=seatType", "Value={seatType}", ENDITEM, 
			"Name=findFlights.x", "Value=72", ENDITEM, 
			"Name=findFlights.y", "Value=4", ENDITEM, 
			LAST);
		
		end_transaction(tName, status);
		lr_think_time(4);
		
		tName = "05.Choice_Flight";
		lr_start_transaction(tName);

		lr_save_string(lr_eval_string(lr_paramarr_random("outFlight")),"randomTicket");
//		lr_output_message(lr_eval_string("{randomTicket}"));
	
		status = web_submit_data("reservations.pl_5", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t14.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=outboundFlight", "Value={randomTicket}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=seatType", "Value={seatType}", ENDITEM, 
			"Name=seatPref", "Value={seatPref}", ENDITEM, 
			"Name=reserveFlights.x", "Value=40", ENDITEM, 
			"Name=reserveFlights.y", "Value=13", ENDITEM, 
			LAST);
		
		end_transaction(tName, status);
		lr_think_time(4);
		
		tName = "06.End_Booking";
		lr_start_transaction(tName);
//		lr_output_message(lr_eval_string("{fName}"));
//		lr_output_message(lr_eval_string("{sName}"));
//		lr_output_message("Adress %s, %s", lr_eval_string("{adress}"),lr_eval_string("{home}"));
//		lr_output_message("Credit card %s, %s", lr_eval_string("{cCard}"),lr_eval_string("{cDate}"));
	
		status = web_submit_data("reservations.pl_6", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t15.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=firstName", "Value={fName}", ENDITEM, 
			"Name=lastName", "Value={sName}", ENDITEM, 
			"Name=address1", "Value={adress}", ENDITEM, 
			"Name=address2", "Value={home}", ENDITEM, 
			"Name=pass1", "Value={fName} {sName}", ENDITEM, 
			"Name=creditCard", "Value={cCard}", ENDITEM, 
			"Name=expDate", "Value={cDate}", ENDITEM, 
			"Name=oldCCOption", "Value=", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=seatType", "Value={seatType}", ENDITEM, 
			"Name=seatPref", "Value={seatPref}", ENDITEM, 
			"Name=outboundFlight", "Value={randomTicket}", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=returnFlight", "Value=", ENDITEM, 
			"Name=JSFormSubmit", "Value=off", ENDITEM, 
			"Name=.cgifields", "Value=saveCC", ENDITEM, 
			"Name=buyFlights.x", "Value=73", ENDITEM, 
			"Name=buyFlights.y", "Value=7", ENDITEM, 
			LAST);
			
		end_transaction(tName, status);
		lr_think_time(4);
//	}
//	else {
//		lr_start_transaction("createTicket_2");
//		web_reg_save_param_ex(
//		    "ParamName=outFlight", 
//		    "LB/IC=name=\"outboundFlight\" value=\"",
//		    "RB/IC=\"",
//		    "Ordinal=all");
//		
//		web_reg_save_param_ex(
//		    "ParamName=returnFlight", 
//		    "LB/IC=name=\"returnFlight\" value=\"",
//		    "RB/IC=\"",
//		    "Ordinal=all");
//		
//		status = web_submit_form("reservations.pl", 
//			"Snapshot=t4.inf", 
//			ITEMDATA, 
//			"Name=depart", "Value={city}", ENDITEM, 
//			"Name=departDate", "Value={date1}", ENDITEM, 
//			"Name=arrive", "Value={city}", ENDITEM, 
//			"Name=returnDate", "Value={date2}", ENDITEM, 
//			"Name=numPassengers", "Value=1", ENDITEM, 
//			"Name=roundtrip", "Value=on", ENDITEM, 
//			"Name=seatPref", "Value={seatPref}", ENDITEM, 
//			"Name=seatType", "Value={seatType}", ENDITEM, 
//			"Name=findFlights.x", "Value=64", ENDITEM, 
//			"Name=findFlights.y", "Value=11", ENDITEM, 
//			LAST);
//		
//		lr_end_transaction("createTicket_2");
//		lr_think_time(4);
//		
//		lr_start_transaction("createTicket_3");
//
//		lr_save_string(lr_eval_string(lr_paramarr_random("outFlight")),"randomTicket1");
////		lr_output_message(lr_eval_string("{randomTicket1}"));
//		lr_save_string(lr_eval_string(lr_paramarr_random("returnFlight")),"randomTicket2");
////		lr_output_message(lr_eval_string("{randomTicket2}"));
//	
//		status = web_submit_form("reservations.pl_2", 
//			"Snapshot=t5.inf", 
//			ITEMDATA, 
//			"Name=outboundFlight", "Value={randomTicket1}", ENDITEM, 
//			"Name=returnFlight", "Value={randomTicket2}", ENDITEM, 
//			"Name=reserveFlights.x", "Value=3", ENDITEM, 
//			"Name=reserveFlights.y", "Value=10", ENDITEM, 
//			LAST);
//	
//		lr_end_transaction("createTicket_3");
//		lr_think_time(4);
//		
//		lr_start_transaction("createTicket_4");
//
////		lr_output_message(lr_eval_string("{fName}"));
////		lr_output_message(lr_eval_string("{sName}"));
////		lr_output_message("Adress %s, %s", lr_eval_string("{adress}"),lr_eval_string("{home}"));
////		lr_output_message("Credit card %s, %s", lr_eval_string("{cCard}"),lr_eval_string("{cDate}"));
////	
//		status = web_submit_form("reservations.pl_3", 
//			"Snapshot=t6.inf", 
//			ITEMDATA, 
//			"Name=firstName", "Value={fName}", ENDITEM, 
//			"Name=lastName", "Value={sName}", ENDITEM, 
//			"Name=address1", "Value={adress}", ENDITEM, 
//			"Name=address2", "Value={home}", ENDITEM, 
//			"Name=pass1", "Value={fName} {sName}", ENDITEM, 
//			"Name=creditCard", "Value={cCard}", ENDITEM, 
//			"Name=expDate", "Value={cDate}", ENDITEM, 
//			"Name=saveCC", "Value={randBoolean}", ENDITEM, 
//			"Name=buyFlights.x", "Value=49", ENDITEM, 
//			"Name=buyFlights.y", "Value=14", ENDITEM, 
//			LAST);
//
//		lr_end_transaction("createTicket_4");
//		lr_think_time(4);
//	}
	
	return 0;
}