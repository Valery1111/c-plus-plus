
#include <iostream>
#include <vector>

class Product
{
public:
	virtual void print() const = 0;
	virtual ~Product() = default;
};

class Product1 : public Product
{
public:
	void print() const override
	{
		std::cout << "Product1" << std::endl;
	};
};

class Product2 : public Product
{
public:
	void print() const override
	{
		std::cout << "Product2" << std::endl;
	};
};

class Product3 : public Product
{
public:
	void print() const override
	{
		std::cout << "Product3" << std::endl;
	};
};

class Cashbox
{
public:
	virtual Product * create() const = 0;
	virtual ~Cashbox() = default;
};

class Product1_Cashbox : public Cashbox
{
public:
	Product * create() const override
	{
		return new Product1;
	}
};

class Product2_Cashbox : public Cashbox
{
public:
	Product * create() const override
	{
		return new Product2;
	}
};

class Product3_Cashbox : public Cashbox
{
public:
	Product * create() const override
	{
		return new Product1;
	}
};

int main(int argc, char ** argv)
{
	Product1_Cashbox  * product1_cashbox  = new Product1_Cashbox;
	Product2_Cashbox  * product2_cashbox  = new Product2_Cashbox;
	Product3_Cashbox  * product3_cashbox  = new Product3_Cashbox;

	std::vector < Product * > products;

	products.push_back(product1_cashbox->create());
	products.push_back(product1_cashbox->create());
	products.push_back(product1_cashbox->create());

	for (std::size_t i = 0; i < products.size(); ++i)
		products.at(i)->print();

	system("pause");

	return EXIT_SUCCESS;
}
