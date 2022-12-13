#pragma once

class inventory {
private:
	// Room type[Price, Revenue, Total rooms, Taken rooms, Free rooms]
	int room_courtyard[5] = { 125, 0, 70, 0, 70 };
	int room_scenic[5] = { 145, 0, 35, 0, 35 };
	int room_deluxe_suite[5] = { 350, 0, 15, 0, 15 };
	int room_penthouse[5] = { 1135, 0, 2, 0, 2 };

	int total_room;
	int total_taken;
	int total_free;
	int total_revenue;

	void update() {
		total_room = room_courtyard[2] + room_scenic[2] + room_deluxe_suite[2] + room_penthouse[2];;
		total_taken = room_courtyard[3] + room_scenic[3] + room_deluxe_suite[3] + room_penthouse[3];
		total_free = room_courtyard[4] + room_scenic[4] + room_deluxe_suite[4] + room_penthouse[4];
		total_revenue = room_courtyard[1] + room_scenic[1] + room_deluxe_suite[1] + room_penthouse[1];
	}

	friend class display;
public:

}inventory;

class display {
private:
	int new_date = 1;
	int new_guy = 1;
	int new_day = 0;
	int new_day1 = 0;
	int new_day2 = 0;
	int new_day3 = 0;

	// What the user types.
	std::string input;

	// The error changes depending upon the users input.
	std::string error;

	// The dates are saved here from 2 to 99.
	// 0 is used as the current shown date, 1 is the new chosen date.
	std::string todays_date[100] = {};
	std::string todays_guy[1200] = {};
	std::string todays_guy1[1200] = {};
	std::string todays_guy2[1200] = {};
	std::string todays_guy3[1200] = {};

	// This saves all the information about that date from 24 to 1199.
	int saved_dates[1200] = {};

	// These are used to save to the next place in the previus arrays.
	int date_number = 1;
	int saved_number = 23;

	void save_change_date() {
		todays_date[1] = date();

		if (todays_date[1] != todays_date[0]) {
			// if user has chosen a date that isn't the same as the current one.
			for (int i = 2; i < 100; i++) {

				if (todays_date[1] == todays_date[i]) {
					// if user has chosen an already existing date.
					todays_date[0] = todays_date[i];

					// This links the saved data to the current data.
					inventory.room_courtyard[1] = saved_dates[i * 12];
					inventory.room_scenic[1] = saved_dates[(i * 12) + 1];
					inventory.room_deluxe_suite[1] = saved_dates[(i * 12) + 2];
					inventory.room_penthouse[1] = saved_dates[(i * 12) + 3];

					inventory.room_courtyard[3] = saved_dates[(i * 12) + 4];
					inventory.room_scenic[3] = saved_dates[(i * 12) + 5];
					inventory.room_deluxe_suite[3] = saved_dates[(i * 12) + 6];
					inventory.room_penthouse[3] = saved_dates[(i * 12) + 7];

					inventory.room_courtyard[4] = saved_dates[(i * 12) + 8];
					inventory.room_scenic[4] = saved_dates[(i * 12) + 9];
					inventory.room_deluxe_suite[4] = saved_dates[(i * 12) + 10];
					inventory.room_penthouse[4] = saved_dates[(i * 12) + 11];

					i = 101;
				}
				else if (i == 99) {
					new_date++;
					new_guy++;
					// if user has chosen a brand new date.
					todays_date[0] = todays_date[1];

					date_number++;
					todays_date[date_number] = todays_date[0];

					saved_number++;
					saved_dates[saved_number] = inventory.room_courtyard[1];
					saved_number++;
					saved_dates[saved_number] = inventory.room_scenic[1];
					saved_number++;
					saved_dates[saved_number] = inventory.room_deluxe_suite[1];
					saved_number++;
					saved_dates[saved_number] = inventory.room_penthouse[1];
					saved_number++;
					saved_dates[saved_number] = inventory.room_courtyard[3];
					saved_number++;
					saved_dates[saved_number] = inventory.room_scenic[3];
					saved_number++;
					saved_dates[saved_number] = inventory.room_deluxe_suite[3];
					saved_number++;
					saved_dates[saved_number] = inventory.room_penthouse[3];
					saved_number++;
					saved_dates[saved_number] = inventory.room_courtyard[4];
					saved_number++;
					saved_dates[saved_number] = inventory.room_scenic[4];
					saved_number++;
					saved_dates[saved_number] = inventory.room_deluxe_suite[4];
					saved_number++;
					saved_dates[saved_number] = inventory.room_penthouse[4];

					inventory.room_courtyard[1] = 0;
					inventory.room_scenic[1] = 0;
					inventory.room_deluxe_suite[1] = 0;
					inventory.room_penthouse[1] = 0;

					inventory.room_courtyard[3] = 0;
					inventory.room_scenic[3] = 0;
					inventory.room_deluxe_suite[3] = 0;
					inventory.room_penthouse[3] = 0;

					inventory.room_courtyard[4] = 75;
					inventory.room_scenic[4] = 35;
					inventory.room_deluxe_suite[4] = 15;
					inventory.room_penthouse[4] = 2;
				}
			}
		}
	}

public:

	std::string date() {
		system("CLS");
		std::cout << "\n\n      Please Type in a Date.\n      > ";
		std::string input_date;
		getline(std::cin, input_date);
		return input_date;
	}

	int title() {
		error = "\n\n   Which room will be reserved? Please type the number.\n   > ";
		
		save_change_date();

		while (true) {
			inventory.update();
			system("CLS");
			std::cout << "For: " + todays_date[0];
			std::cout << "\n      - ROOMS -";
			std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[2]);
			std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[2]);
			std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[2]);
			std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[2]);
			std::cout << "\n      Total:                     " + std::to_string(inventory.total_room);
			std::cout << "\n\n      - TAKEN ROOMS -";
			std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[3]);
			std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[3]);
			std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[3]);
			std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[3]);
			std::cout << "\n      Total:                     " + std::to_string(inventory.total_taken);
			std::cout << "\n\n      - FREE ROOMS -";
			std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[4]);
			std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[4]);
			std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[4]);
			std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[4]);
			std::cout << "\n      Total:                     " + std::to_string(inventory.total_free);
			std::cout << "\n\n   Final revenue for " + todays_date[0] + ": $" + std::to_string(inventory.total_revenue);
			std::cout << "\n   To pick a new date type 5 or type 6 to see all of them.";
			std::cout << error;
			getline(std::cin, input);

			if (input == "1") {
				if (inventory.room_courtyard[4] == 0) {
					error = "\n\n   Which room will be reserved? Please type the number.\n   This room is taken.\n   > ";
				}
				else {
					error = "\n\n   The room will be reserved under what name?\n   > ";
					inventory.update();
					system("CLS");
					std::cout << "For: " + todays_date[0];
					std::cout << "\n      - ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[2]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[2]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[2]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[2]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_room);
					std::cout << "\n\n      - TAKEN ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[3]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[3]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[3]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[3]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_taken);
					std::cout << "\n\n      - FREE ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[4]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[4]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[4]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[4]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_free);
					std::cout << "\n\n   Final revenue for " + todays_date[0] + ": $" + std::to_string(inventory.total_revenue);
					std::cout << "\n   To pick a new date type 5 or type 6 to see all of them.";
					std::cout << error;
					std::string abc;
					getline(std::cin, abc);
					inventory.room_courtyard[1] += inventory.room_courtyard[0];
					inventory.room_courtyard[3] += 1;
					inventory.room_courtyard[4] -= 1;
					new_day++;
					for (int i = new_guy; i <= new_date; i++) {
						todays_guy[i * 4 + (new_day - 1)] = abc;
					}

					error = "\n\n   Which room will be reserved? Please type the number.\n   A Standard Room, Courtyard have been reserved.\n   > ";
				}
			}
			else if (input == "2") {
				if (inventory.room_scenic[4] == 0) {
					error = "\n\n   Which room will be reserved? Please type the number.\n   This room is taken.\n   > ";
				}
				else {
					error = "\n\n   The room will be reserved under what name?\n   > ";
					inventory.update();
					system("CLS");
					std::cout << "For: " + todays_date[0];
					std::cout << "\n      - ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[2]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[2]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[2]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[2]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_room);
					std::cout << "\n\n      - TAKEN ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[3]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[3]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[3]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[3]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_taken);
					std::cout << "\n\n      - FREE ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[4]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[4]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[4]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[4]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_free);
					std::cout << "\n\n   Final revenue for " + todays_date[0] + ": $" + std::to_string(inventory.total_revenue);
					std::cout << "\n   To pick a new date type 5 or type 6 to see all of them.";
					std::cout << error;
					std::string abc;
					getline(std::cin, abc);
					inventory.room_scenic[1] += inventory.room_scenic[0];
					inventory.room_scenic[3] += 1;
					inventory.room_scenic[4] -= 1;
					error = "\n\n   Which room will be reserved? Please type the number.\n   A Standard Room, Scenic have been reserved.\n   > ";
					new_day1++;
					for (int i = new_guy; i <= new_date; i++) {
						todays_guy1[i * 4 + (new_day1 - 1)] = abc;
					}
				}
			}
			else if (input == "3") {
				if (inventory.room_deluxe_suite[4] == 0) {
					error = "\n\n   Which room will be reserved? Please type the number.\n   This room is taken.\n   > ";
				}
				else {
					error = "\n\n   The room will be reserved under what name?\n   > ";
					inventory.update();
					system("CLS");
					std::cout << "For: " + todays_date[0];
					std::cout << "\n      - ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[2]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[2]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[2]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[2]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_room);
					std::cout << "\n\n      - TAKEN ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[3]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[3]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[3]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[3]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_taken);
					std::cout << "\n\n      - FREE ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[4]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[4]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[4]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[4]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_free);
					std::cout << "\n\n   Final revenue for " + todays_date[0] + ": $" + std::to_string(inventory.total_revenue);
					std::cout << "\n   To pick a new date type 5 or type 6 to see all of them.";
					std::cout << error;
					std::string abc;
					getline(std::cin, abc);
					inventory.room_deluxe_suite[1] += inventory.room_deluxe_suite[0];
					inventory.room_deluxe_suite[3] += 1;
					inventory.room_deluxe_suite[4] -= 1;
					error = "\n\n   Which room will be reserved? Please type the number.\n   A Deluxe Suite have been reserved.\n   > ";
					new_day2++;
					for (int i = new_guy; i <= new_date; i++) {
						todays_guy2[i * 4 + (new_day2 - 1)] = abc;
					}
				}
			}
			else if (input == "4") {
				if (inventory.room_penthouse[4] == 0) {
					error = "\n\n   Which room will be reserved? Please type the number.\n   This room is taken.\n   > ";
				}
				else {
					error = "\n\n   The room will be reserved under what name?\n   > ";
					inventory.update();
					system("CLS");
					std::cout << "For: " + todays_date[0];
					std::cout << "\n      - ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[2]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[2]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[2]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[2]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_room);
					std::cout << "\n\n      - TAKEN ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[3]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[3]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[3]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[3]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_taken);
					std::cout << "\n\n      - FREE ROOMS -";
					std::cout << "\n   1. Standard Rooms, Courtyard: " + std::to_string(inventory.room_courtyard[4]);
					std::cout << "\n   2. Standard Room, Scenic:     " + std::to_string(inventory.room_scenic[4]);
					std::cout << "\n   3. Deluxe Suite:              " + std::to_string(inventory.room_deluxe_suite[4]);
					std::cout << "\n   4. Penthouse:                 " + std::to_string(inventory.room_penthouse[4]);
					std::cout << "\n      Total:                     " + std::to_string(inventory.total_free);
					std::cout << "\n\n   Final revenue for " + todays_date[0] + ": $" + std::to_string(inventory.total_revenue);
					std::cout << "\n   To pick a new date type 5 or type 6 to see all of them.";
					std::cout << error;
					std::string abc;
					getline(std::cin, abc);
					inventory.room_penthouse[1] += inventory.room_penthouse[0];
					inventory.room_penthouse[3] += 1;
					inventory.room_penthouse[4] -= 1;
					error = "\n\n   Which room will be reserved? Please type the number.\n   A Penthouse have been reserved.\n   > ";
					new_day3++;
					for (int i = new_guy; i <= new_date; i++) {
						todays_guy3[i * 4 + (new_day3 - 1)] = abc;
					}
				}
			}
			else if (input == "5") {

				for (int b = 2; b < 100; b++) {
					if (todays_date[0] == todays_date[b]) {

						// This saves the current data to the saved data.
						saved_dates[b * 12] = inventory.room_courtyard[1];
						saved_dates[(b * 12) + 1] = inventory.room_scenic[1];
						saved_dates[(b * 12) + 2] = inventory.room_deluxe_suite[1];
						saved_dates[(b * 12) + 3] = inventory.room_penthouse[1];
						saved_dates[(b * 12) + 4] = inventory.room_courtyard[3];
						saved_dates[(b * 12) + 5] = inventory.room_scenic[3];
						saved_dates[(b * 12) + 6] = inventory.room_deluxe_suite[3];
						saved_dates[(b * 12) + 7] = inventory.room_penthouse[3];
						saved_dates[(b * 12) + 8] = inventory.room_courtyard[4];
						saved_dates[(b * 12) + 9] = inventory.room_scenic[4];
						saved_dates[(b * 12) + 10] = inventory.room_deluxe_suite[4];
						saved_dates[(b * 12) + 11] = inventory.room_penthouse[4];
					}
				}

				save_change_date();
				
			}

			else if (input == "6") {
				system("CLS");
				for (int b = 2; b < 100; b++) {
					if (todays_date[0] == todays_date[b]) {

						// This saves the current data to the saved data.
						saved_dates[b * 12] = inventory.room_courtyard[1];
						saved_dates[(b * 12) + 1] = inventory.room_scenic[1];
						saved_dates[(b * 12) + 2] = inventory.room_deluxe_suite[1];
						saved_dates[(b * 12) + 3] = inventory.room_penthouse[1];
						saved_dates[(b * 12) + 4] = inventory.room_courtyard[3];
						saved_dates[(b * 12) + 5] = inventory.room_scenic[3];
						saved_dates[(b * 12) + 6] = inventory.room_deluxe_suite[3];
						saved_dates[(b * 12) + 7] = inventory.room_penthouse[3];
						saved_dates[(b * 12) + 8] = inventory.room_courtyard[4];
						saved_dates[(b * 12) + 9] = inventory.room_scenic[4];
						saved_dates[(b * 12) + 10] = inventory.room_deluxe_suite[4];
						saved_dates[(b * 12) + 11] = inventory.room_penthouse[4];
					}
				}

				save_file.open("save.txt", std::ios::out);//write
				if (save_file.is_open()) {
					for (int i = 2; i <= new_date; i++) {
						save_file << "\n   " + std::to_string(i - 1) + ") " + todays_date[i] + " Rooms:";
						for (int a = 1; a <= saved_dates[i * 12 + 4]; a++) {
							save_file << " " + todays_guy[i * 4 + (a - 1)] + " " + std::to_string(a + 100) + ",";
						}
						for (int a = 1; a <= saved_dates[i * 12 + 5]; a++) {
							save_file << " " + todays_guy1[i * 4 + (a - 1)] + " " + std::to_string(a + 200) + ",";
						}
						for (int a = 1; a <= saved_dates[i * 12 + 6]; a++) {
							save_file << " " + todays_guy2[i * 4 + (a - 1)] + " " + std::to_string(a + 300) + ",";
						}
						for (int a = 1; a <= saved_dates[i * 12 + 7]; a++) {
							save_file << " " + todays_guy3[i * 4 + (a - 1)] + " " + std::to_string(a + 400) + ",";
						}
					}
					save_file.close();
				}

				for (int i = 2; i <= new_date; i++) {
					std::cout << "\n   " + std::to_string(i - 1) + ") " + todays_date[i] + " Rooms:";
					for (int a = 1; a <= saved_dates[i * 12 + 4]; a++) {
						std::cout << " " + todays_guy[i * 4 + (a - 1)] + " " + std::to_string(a + 100) + ",";
					}
					for (int a = 1; a <= saved_dates[i * 12 + 5]; a++) {
						std::cout << " " + todays_guy1[i * 4 + (a - 1)] + " " + std::to_string(a + 200) + ",";
					}
					for (int a = 1; a <= saved_dates[i * 12 + 6]; a++) {
						std::cout << " " + todays_guy2[i * 4 + (a - 1)] + " " + std::to_string(a + 300) + ",";
					}
					for (int a = 1; a <= saved_dates[i * 12 + 7]; a++) {
						std::cout << " " + todays_guy3[i * 4 + (a - 1)] + " " + std::to_string(a + 400) + ",";
					}
					
				}
				std::cout << "\n\n   > ";
				std::string select;
				getline(std::cin, select);
				for (int ii = 1; ii <= new_date; ii++) {
					if (select == std::to_string(ii)) {

						for (int b = 2; b < 100; b++) {
							if (todays_date[0] == todays_date[b]) {

								// This saves the current data to the saved data.
								saved_dates[b * 12] = inventory.room_courtyard[1];
								saved_dates[(b * 12) + 1] = inventory.room_scenic[1];
								saved_dates[(b * 12) + 2] = inventory.room_deluxe_suite[1];
								saved_dates[(b * 12) + 3] = inventory.room_penthouse[1];
								saved_dates[(b * 12) + 4] = inventory.room_courtyard[3];
								saved_dates[(b * 12) + 5] = inventory.room_scenic[3];
								saved_dates[(b * 12) + 6] = inventory.room_deluxe_suite[3];
								saved_dates[(b * 12) + 7] = inventory.room_penthouse[3];
								saved_dates[(b * 12) + 8] = inventory.room_courtyard[4];
								saved_dates[(b * 12) + 9] = inventory.room_scenic[4];
								saved_dates[(b * 12) + 10] = inventory.room_deluxe_suite[4];
								saved_dates[(b * 12) + 11] = inventory.room_penthouse[4];
							}
						}

						todays_date[1] = todays_date[ii + 1];

						if (todays_date[1] != todays_date[0]) {
							// if user has chosen a date that isn't the same as the current one.
							for (int i = 2; i < 100; i++) {

								if (todays_date[1] == todays_date[i]) {
									// if user has chosen an already existing date.
									todays_date[0] = todays_date[i];

									// This links the saved data to the current data.
									inventory.room_courtyard[1] = saved_dates[i * 12];
									inventory.room_scenic[1] = saved_dates[(i * 12) + 1];
									inventory.room_deluxe_suite[1] = saved_dates[(i * 12) + 2];
									inventory.room_penthouse[1] = saved_dates[(i * 12) + 3];

									inventory.room_courtyard[3] = saved_dates[(i * 12) + 4];
									inventory.room_scenic[3] = saved_dates[(i * 12) + 5];
									inventory.room_deluxe_suite[3] = saved_dates[(i * 12) + 6];
									inventory.room_penthouse[3] = saved_dates[(i * 12) + 7];

									inventory.room_courtyard[4] = saved_dates[(i * 12) + 8];
									inventory.room_scenic[4] = saved_dates[(i * 12) + 9];
									inventory.room_deluxe_suite[4] = saved_dates[(i * 12) + 10];
									inventory.room_penthouse[4] = saved_dates[(i * 12) + 11];

									i = 101;
								}
								else if (i == 99) {
									new_date++;
									// if user has chosen a brand new date.
									todays_date[0] = todays_date[1];

									date_number++;
									todays_date[date_number] = todays_date[0];

									saved_number++;
									saved_dates[saved_number] = inventory.room_courtyard[1];
									saved_number++;
									saved_dates[saved_number] = inventory.room_scenic[1];
									saved_number++;
									saved_dates[saved_number] = inventory.room_deluxe_suite[1];
									saved_number++;
									saved_dates[saved_number] = inventory.room_penthouse[1];
									saved_number++;
									saved_dates[saved_number] = inventory.room_courtyard[3];
									saved_number++;
									saved_dates[saved_number] = inventory.room_scenic[3];
									saved_number++;
									saved_dates[saved_number] = inventory.room_deluxe_suite[3];
									saved_number++;
									saved_dates[saved_number] = inventory.room_penthouse[3];
									saved_number++;
									saved_dates[saved_number] = inventory.room_courtyard[4];
									saved_number++;
									saved_dates[saved_number] = inventory.room_scenic[4];
									saved_number++;
									saved_dates[saved_number] = inventory.room_deluxe_suite[4];
									saved_number++;
									saved_dates[saved_number] = inventory.room_penthouse[4];

									inventory.room_courtyard[1] = 0;
									inventory.room_scenic[1] = 0;
									inventory.room_deluxe_suite[1] = 0;
									inventory.room_penthouse[1] = 0;

									inventory.room_courtyard[3] = 0;
									inventory.room_scenic[3] = 0;
									inventory.room_deluxe_suite[3] = 0;
									inventory.room_penthouse[3] = 0;

									inventory.room_courtyard[4] = 75;
									inventory.room_scenic[4] = 35;
									inventory.room_deluxe_suite[4] = 15;
									inventory.room_penthouse[4] = 2;
								}
							}
						}

						ii = new_date + 1;
					}
				}
			}

			else {
				error = "\n\n   Which room will be reserved? Please type the number.\n   I don't understand.\n   > ";
			}

		}
	}

}display;