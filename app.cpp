#include <iostream>
#include <string>
#include <ctime>
#include <list>

class Product
{
private:
	int id;
	std::string name;
	int price;

public:
	Product() : name(""), price(0) {}
	~Product() = default;

	bool create(std::string input_name_product, int input_price_product)
	{
		id = rand() % 1000 + 1;
		name = input_name_product;
		price = input_price_product;
		return true;
	}
	int getId() { return id; }
	std::string getName() { return name; }
	int getPrice() { return price; }
	void setPrice(int newPrice) { price = newPrice; }
};

int main()
{
	char input_option;
	char admin_input_option;
	char client_input_option;
	std::string input_name_product;
	int input_price_product;
	int input_id_product;
	int input_new_price_product;
	int client_id_product_to_car;
	std::list<Product> products;
	std::list<Product>::iterator it;
	std::list<Product> car;
	std::list<Product>::iterator iteratorCar;
	long total = 0;

	while (1)
	{

		system("cls");
		std::cout << "___________Super Market Application___________" << std::endl;
		std::cout << "a) Client" << std::endl;
		std::cout << "b) Admin" << std::endl;
		std::cout << "c) Close Application" << std::endl;
		std::cout << "Choice the option: ";
		std::cin >> input_option;

		if (input_option == 'c')
		{
			std::cout << "Thanks for see the App" << std::endl;
			break;
		}
		// admin View
		if (input_option == 'b')
		{
			while (1)
			{

				system("cls");
				std::cout << "Welcome To Admin View" << std::endl;
				std::cout << "a) Show Products" << std::endl;
				std::cout << "b) Add a New Product" << std::endl;
				std::cout << "c) Change Price" << std::endl;
				std::cout << "d) Close Application" << std::endl;
				std::cout << "Choice Option: ";
				std::cin >> admin_input_option;
				if (admin_input_option == 'a')
				{
					for (it = products.begin(); it != products.end(); it++)
					{
						std::cout << it->getId() << "|" << it->getName() << "|" << it->getPrice() << std::endl;
					}
				}
				if (admin_input_option == 'b')
				{
					// input name product
					std::cout << "Enter the name of product: ";
					std::cin.clear();
					std::cin.ignore();
					std::getline(std::cin, input_name_product);
					// input price product
					std::cout << "Enter the price of product: ";
					std::cin >> input_price_product;

					Product newProduct;
					newProduct.create(input_name_product, input_price_product);
					products.push_back(newProduct);
				}
				if (admin_input_option == 'c')
				{
					system("cls");
					std::cout << "Please Enter the ID of Product: ";
					std::cin >> input_id_product;
					for (it = products.begin(); it != products.end(); it++)
					{
						if (input_id_product == it->getId())
						{
							std::cout << "The Product Found is 👌" << std::endl;
							std::cout << "Name Product: " << it->getName() << std::endl;
							std::cout << "Id Product: " << it->getId() << std::endl;
							std::cout << "Price Product: " << it->getPrice() << std::endl;
							std::cout << "Please Enter the new Price for Product " << it->getName() << std::endl;
							std::cout << "New Price: ";
							std::cin >> input_new_price_product;
							it->setPrice(input_new_price_product);
						}
					}
				}
				if (admin_input_option == 'd')
				{
					std::cout << "Thanks for see the Application" << std::endl;
					break;
				}
			}
		}
		// client view
		if (input_option == 'a')
		{
			while (1)
			{
				system("cls");
				std::cout << "Welcome to Client View" << std::endl;
				std::cout << "a) show all Products" << std::endl;
				std::cout << "b) add product to car" << std::endl;
				std::cout << "c) pay the products" << std::endl;
				std::cout << "d) Close de admin view" << std::endl;
				std::cout << "Choice the option: ";
				std::cin >> client_input_option;

				if (client_input_option == 'd')
				{
					std::cout << "Thanks For visit the Cliet View" << std::endl;
					break;
				}
				if (client_input_option == 'a')
				{
					for (it = products.begin(); it != products.end(); it++)
					{
						std::cout << it->getId() << "|" << it->getName() << "|" << it->getPrice() << std::endl;
					}
				}
				if (client_input_option == 'b')
				{
					std::cout << "\n\n\n";
					std::cout << "Welcome To Car 🛒" << std::endl;
					if (car.empty())
					{
						std::cout << "Add Your First Product To Car" << std::endl;
					}
					if (!car.empty())
					{
						std::cout << "Your Car Actually is: " << std::endl;
						for (iteratorCar = car.begin(); iteratorCar != car.end(); iteratorCar++)
						{
							std::cout << iteratorCar->getId() << "|" << iteratorCar->getName() << "|" << iteratorCar->getPrice() << std::endl;
						}
					}
					std::cout << "Please Enter The Id Of Product For Add To Car: ";
					std::cin >> client_id_product_to_car;
					for (iteratorCar = products.begin(); iteratorCar != products.end(); iteratorCar++)
					{
						if (client_id_product_to_car == iteratorCar->getId())
						{
							Product newProdcutToCar;
							newProdcutToCar.create(iteratorCar->getName(), iteratorCar->getPrice());
							car.push_back(newProdcutToCar);
						}
					}
				}
				if (client_input_option == 'c')
				{
					std::cout << "Confirm Your Pay All Products Are: " << std::endl;
					for (iteratorCar = car.begin(); iteratorCar != car.end(); iteratorCar++)
					{
						std::cout << iteratorCar->getId() << "|" << iteratorCar->getName() << "|" << iteratorCar->getPrice() << std::endl;
						total += iteratorCar->getPrice();
					}
					std::cout << "The Total for Pay is: " << total << std::endl;
				}
			}
		}
	}
}
