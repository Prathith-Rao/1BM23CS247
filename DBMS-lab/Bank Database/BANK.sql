create database bank_247;
use bank_247;

create table branch(
branch_name varchar(30),
branch_city varchar(25),
assets int,
primary key (branch_name));

create table bankaccount(
accno int,
branch_name varchar(30),
balance int,
primary key(accno),
foreign key(branch_name) references branch(branch_name));

create table bankcustomer(
customername varchar(20),
customer_street varchar(30),
customer_city varchar(35),
primary key(customername));

create table depositer(
customername varchar(20),
accno int,
PRIMARY KEY(customername,accno),
foreign key(accno) references bankaccount(accno),
foreign key(customername) references bankcustomer(customername));

create table loan(
loan_number int,
branch_name varchar(30),
amount int,
primary key(loan_number),
foreign key(branch_name) references branch(branch_name));

create table borrower(
loan_number int,
customername varchar(20),
primary key(loan_number),
foreign key(loan_number) references loan(loan_number),
foreign key(customername) references bankcustomer(customername));

insert into branch values("SBI_Chamrajpet","Bangalore",50000);
insert into branch values("SBI_ResidencyRoad","Bangalore",10000);
insert into branch values("SBI_ShivajiRoad","Bombay",20000);
insert into branch values("SBI_Parliamentroad","Delhi",10000);
insert into branch values("SBI_Jantarmantar","Delhi",20000);

insert into bankaccount values(1,"SBI_Chamrajpet",2000);
insert into bankaccount values(2,"SBI_ResidencyRoad",5000);
insert into bankaccount values(3,"SBI_ShivajiRoad",6000);
insert into bankaccount values(4,"SBI_Parliamentroad",9000);
insert into bankaccount values(5,"SBI_Jantarmantar",8000);
insert into bankaccount values(6,"SBI_ShivajiRoad",4000);
insert into bankaccount values(8,"SBI_ResidencyRoad",4000);
insert into bankaccount values(9,"SBI_Parliamentroad",3000);
insert into bankaccount values(10,"SBI_ResidencyRoad",5000);
insert into bankaccount values(11,"SBI_Jantarmantar",2000);
                                
insert into bankcustomer values("Avinash","BUll_temple_Road","Bangalore");
insert into bankcustomer values("Dinesh","Bannergatta_Road","Bangalore");
insert into bankcustomer values("Mohan","NationaCollege_Road","Bangalore");
insert into bankcustomer values("Nikil","Akbar_Road","Delhi");
insert into bankcustomer values("Ravi","Prithviraj_Road","Delhi");


insert into depositer values("Avinash",1);
insert into depositer values("Dinesh",2);
insert into depositer values("Nikil",4);
insert into depositer values("Ravi",5);
insert into depositer values("Avinash",8);
insert into depositer values("Nikil",9);
insert into depositer values("Dinesh",10);
insert into depositer values("Nikil",11);

insert into loan values(1,"SBI_Chamrajpet",1000);
insert into loan values(2,"SBI_ResidencyRoad",2000);
insert into loan values(3,"SBI_ShivajiRoad",3000);
insert into loan values(4,"SBI_Parliamentroad",4000);
insert into loan values(5,"SBI_Jantarmantar",5000);

insert into borrower values(1,"Mohan");
insert into borrower values(2,"Avinash");
insert into borrower values(3,"Dinesh");
insert into borrower values(4,"Mohan");
insert into borrower values(5,"Nikil");

select * from branch;

select * from bankaccount;

select * from bankcustomer;

select * from depositer;

select * from loan;

select * from borrower;

select branch_name,(assets/100000) as assets_in_lakhs from branch;

select d.customername from depositer d,bankaccount b
where b.branch_name="SBI_ResidencyRoad" and
d.accno=b.accno
group by d.customername having count(d.accno)>=2;

select d.customername from depositer d,bankaccount b
where d.accno=b.accno
group by d.customername having count(d.accno)>=2;

select branch_name,sum(amount) as Total_loan_amount from loan
group by branch_name;

create view sum_of_loan
as select branch_name,sum(amount) from loan
group by branch_name;

select * from sum_of_loan;

select distinct s.customername from depositer s
where not exists ((select branch_name from branch where branch_city="Delhi") except (select r.branch_name from depositer t, bankaccount r 
where t.accno=r.accno and
s.customername=t.customername));

select distinct customername from borrower
where customername not in (select customername from depositer);

select  distinct b.customername from borrower b,loan l ,depositer d,branch br
where b.loan_number=l.loan_number and
l.branch_name=br.branch_name and
br.branch_city="Bangalore" and
b.customername in (select customername from depositer);

select branch_name from branch
where assets > all(select assets from branch 
where branch_city="Bangalore");

