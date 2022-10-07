create database WeKlean

use WeKlean

go

create table Employee(
EmployeeID char(5) primary key check(EmployeeID like 'EM[0-9][0-9][0-9]'),
EmployeeName varchar(55) not null check(EmployeeName not like ' '),
EmployeeGender varchar(10) NOT NULL CHECK(EmployeeGender IN('Male','Female')),
EmployeeEmail varchar(55) not null,
EmployeeAddress varchar(55) not null,
EmployeePhoneNumber varchar(13) not null
)

insert into Employee values


create table MsSuplier(
SuplierID char(5) primary key check(SuplierID like 'SU[0-9][0-9][0-9]'),
SuplierName varchar(55) not null check(SuplierName not like ' '),
SuplierGender varchar(10) NOT NULL CHECK(SuplierGender IN('Male','Female')),
suplierEmail varchar(55) not null,
SuplierAddress varchar(55) not null,
SuplierPhoneNumber varchar(13) not null
)

insert into MsSuplier values


create table MsCustomer(
CustomerID char(5) primary key check(CustomerID like 'CU[0-9][0-9][0-9]'),
CustomerName varchar(55) not null check(CustomerName not like ' '),
CustomerGender varchar(10) NOT NULL CHECK(CustomerGender IN('Male','Female')),
CustomerEmail varchar(55) not null,
CustomerAddress varchar(55) not null,
CustomerPhoneNumber varchar(13) not null
)

insert into MsCustomer values


create table Product(
ProductID char(5) primary key check(ProductID like 'PR[0-9][0-9][0-9]'),
ProductName varchar(55) not null check(len(ProductName) > 5),
ProductPrice int not null check(ProductPrice between 10000 and 500000)
)

insert into Product values


create table Purchase(
PurchaseID char(5) primary key check(PurchaseID like 'PU[0-9][0-9][0-9]'),
EmployeeID char(5) foreign key references Employee(EmployeeID) on update cascade on delete cascade not null,
SuplierID char(5) foreign key references MsSuplier(SuplierID) not null,
PurchaseDate date not null
)

insert into Purchase values


create table PurchaseDetail(
PurchaseID char(5) foreign key references Purchase(PurchaseID) on update cascade on delete cascade not null,
ProductID char(5) foreign key references MsSuplier(SuplierID) not null,
ProductQuantity int not null check(ProductQuantity > 0)
)

insert into PurchaseDetail values


create table Sales(
SalesID char(5) primary key check(SalesID like 'TR[0-9][0-9][0-9]'),
CustomerID char(5) foreign key references MsCustomer(CustomerID) on update cascade on delete cascade not null,
EmployeeID char(5) foreign key references Employee(EmployeeID) not null,
PurchaseDate date not null
)

insert into Sales values


create table SalesDetail(
SalesID char(5) foreign key references Sales(SalesID) on update cascade on delete cascade not null,
ProductID char(5) foreign key references Product(ProductID) not null,
ProductQuantity int not null
)

insert into SalesDetail values
