vuser_init()
{	
	tName = "01.Enter_WebTours";
	lr_start_transaction(tName);
	
	web_reg_save_param_ex(
	    "ParamName=sessionID", 
	    "LB/IC=name=\"userSession\" value=\"",
	    "RB/IC=\"",
	    "Ordinal=1");
	
	status = web_url("webtours",
		"URL=http://localhost:1080/webtours/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	end_transaction(tName, status);
	lr_think_time(4);

	tName = "02.Login";
	lr_start_transaction(tName);
	
	status = web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=body", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value={sessionID}", ENDITEM, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={pass}", ENDITEM, 
		"Name=login.x", "Value=0", ENDITEM, 
		"Name=login.y", "Value=0", ENDITEM, 
		LAST);
	
	end_transaction(tName, status);
	lr_think_time(4);
	
	return 0;
}
