
Action()
{

		int i=0;
	
	web_custom_request("computers", 
		"URL=http://computer-database.gatling.io/computers", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);



	web_custom_request("bootstrap.min.css", 
		"URL=http://computer-database.gatling.io/assets/stylesheets/bootstrap.min.css", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t2.inf", 
		LAST);

	web_custom_request("main.css", 
		"URL=http://computer-database.gatling.io/assets/stylesheets/main.css", 
		"Method=GET", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t3.inf", 
		LAST);



	lr_think_time(12);


	while(i<9){
	web_custom_request("Add a new computer", 
		"URL=http://computer-database.gatling.io/computers/new", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t4.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("computers_2", 
		"URL=http://computer-database.gatling.io/computers", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers/new", 
		"Snapshot=t5.inf", 
		"Mode=HTTP", 
		"Body=name=Komus+{PCnum}&introduced={date}&discontinued=2020-01-01&company=3", 
		LAST);
		
		
		i=i+1;
	}


	lr_think_time(16);
	
	web_reg_find("Search=All",
		"SaveCount=count",
		"Text=<td><a href=\"/computers/",
		LAST);

	web_custom_request("computers_3", 
		"URL=http://computer-database.gatling.io/computers?f=asus", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t6.inf", 
		"Mode=HTTP", 
		LAST);


	lr_output_message ("% d", atoi (lr_eval_string ("{count}")));

	
	
	
	
	web_custom_request("Play sample application &mdash; Computer database", 
		"URL=http://computer-database.gatling.io/", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers?f=asus", 
		"Snapshot=t7.inf", 
		"Mode=HTTP", 
		LAST);

	lr_think_time(8);

	web_custom_request("computers_4", 
		"URL=http://computer-database.gatling.io/computers?f=ibm", 
		"Method=GET", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://computer-database.gatling.io/computers", 
		"Snapshot=t8.inf", 
		"Mode=HTTP", 
		LAST);

	return 0;
}
