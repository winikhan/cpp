#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

// Constants for input validation
const double MIN_TEMPERATURE = -50.0;
const double MAX_TEMPERATURE = 60.0;
const double MIN_SOIL_MOISTURE = 0.0;
const double MAX_SOIL_MOISTURE = 100.0;
const double MIN_SOIL_QUALITY = 0.0;
const double MAX_SOIL_QUALITY = 1.0;
const double MIN_WEATHER_SCORE = 0.0;
const double MAX_WEATHER_SCORE = 1.0;
const double MIN_MARKET_PRICE = 0.0;

class AgricultureMonitoringSystem {
private:
    // Farm parameters
    double farmSize;
    std::string cropType;
    double soilMoisture;
    double temperature;
    double rainfall;
    double fertilizer;
    double cropWaterNeed;
    double marketPrice;

public:
    // Constructor to initialize default values
    AgricultureMonitoringSystem()
        : farmSize(0), cropType(""), soilMoisture(0), 
          temperature(0), rainfall(0), fertilizer(0), 
          cropWaterNeed(0), marketPrice(0) {}

    // Main menu method
    void runSystem() {
        while (true) {
            displayMainMenu();
            int choice;
            std::cin >> choice;

            switch (choice) {
                case 1: inputFarmDetails(); break;
                case 2: analyzeWeatherConditions(); break;
                case 3: checkSoilHealth(); break;
                case 4: predictCropYield(); break;
                case 5: recommendIrrigation(); break;
                case 6: provideFertilizerGuidance(); break;
                case 7: analyzeMarketPrices(); break;
                case 8: generateFarmReport(); break;
                case 9: 
                    std::cout << "Exiting Agricultural Monitoring System.\n";
                    return;
                default: 
                    std::cout << "Invalid choice. Please try again.\n";
            }
            std::cout << "\nPress Enter to continue...\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
        }
    }

private:
    // Displaying the main menu
    void displayMainMenu() {
        std::cout << "\n===== AGRICULTURAL MONITORING SYSTEM =====\n";
        std::cout << "1. Input Farm Details\n";
        std::cout << "2. Analyze Weather Conditions\n";
        std::cout << "3. Check Soil Health\n";
        std::cout << "4. Predict Crop Yield\n";
        std::cout << "5. Recommend Irrigation\n";
        std::cout << "6. Provide Fertilizer Guidance\n";
        std::cout << "7. Analyze Market Prices\n";
        std::cout << "8. Generate Farm Report\n";
        std::cout << "9. Exit System\n";
        std::cout << "Enter your choice: ";
    }

    // Input farm details (Farm size, crop type)
    void inputFarmDetails() {
        std::cout << "\n----- FARM DETAILS INPUT -----\n";
        std::cout << "Enter Farm Size (acres) [Number > 0]: ";
        while (true) {
            std::cin >> farmSize;
            if (farmSize > 0) break;
            std::cout << "Invalid input. Please enter a positive number for farm size: ";
        }

        std::cin.ignore();
        std::cout << "Enter Crop Type (e.g., Wheat, Corn): ";
        std::getline(std::cin, cropType);
        std::cout << "Farm details recorded successfully!\n";
    }

    // Analyze weather conditions (Temperature, Rainfall)
    void analyzeWeatherConditions() {
        std::cout << "\n----- WEATHER ANALYSIS -----\n";
        std::cout << "Enter Current Temperature (°C) [Number]: ";
        while (true) {
            std::cin >> temperature;
            if (temperature >= MIN_TEMPERATURE && temperature <= MAX_TEMPERATURE) break;
            std::cout << "Invalid input. Please enter a valid temperature (°C): ";
        }

        std::cout << "Enter Rainfall Amount (mm) [Number >= 0]: ";
        while (true) {
            std::cin >> rainfall;
            if (rainfall >= 0) break;
            std::cout << "Invalid input. Please enter a valid rainfall amount (mm): ";
        }

        std::cout << "\nWeather Analysis Report:\n";
        std::cout << "Temperature: " << temperature << "°C\n";
        std::cout << "Rainfall: " << rainfall << " mm\n";

        if (temperature > 35) {
            std::cout << "WARNING: High temperature risk for crops!\n";
        }
        if (rainfall < 10) {
            std::cout << "ALERT: Low rainfall, consider irrigation!\n";
        }
    }

    // Check soil health based on moisture level
    void checkSoilHealth() {
        std::cout << "\n----- SOIL HEALTH CHECK -----\n";
        std::cout << "Enter Soil Moisture Level (%) [0 - 100]: ";
        while (true) {
            std::cin >> soilMoisture;
            if (soilMoisture >= MIN_SOIL_MOISTURE && soilMoisture <= MAX_SOIL_MOISTURE) break;
            std::cout << "Invalid input. Please enter a valid soil moisture level (0-100): ";
        }

        std::cout << "\nSoil Health Assessment:\n";
        if (soilMoisture < 20) {
            std::cout << "Soil Moisture: LOW\n";
            std::cout << "Recommendation: Urgent Irrigation Required!\n";
        } else if (soilMoisture >= 20 && soilMoisture <= 50) {
            std::cout << "Soil Moisture: MODERATE\n";
            std::cout << "Recommendation: Monitor and plan irrigation.\n";
        } else {
            std::cout << "Soil Moisture: OPTIMAL\n";
            std::cout << "Soil conditions are good for crop growth.\n";
        }
    }

    // Predict crop yield based on soil quality and weather conditions
    void predictCropYield() {
        std::cout << "\n----- CROP YIELD PREDICTION -----\n";
        double soilQuality, weatherScore;

        std::cout << "Enter Soil Quality (0-1) [Decimal]: ";
        while (true) {
            std::cin >> soilQuality;
            if (soilQuality >= MIN_SOIL_QUALITY && soilQuality <= MAX_SOIL_QUALITY) break;
            std::cout << "Invalid input. Please enter a valid soil quality value (0-1): ";
        }

        std::cout << "Enter Weather Suitability Score (0-1) [Decimal]: ";
        while (true) {
            std::cin >> weatherScore;
            if (weatherScore >= MIN_WEATHER_SCORE && weatherScore <= MAX_WEATHER_SCORE) break;
            std::cout << "Invalid input. Please enter a valid weather score (0-1): ";
        }

        double predictedYield = farmSize * soilQuality * weatherScore * 2.5;
        std::cout << "\nYield Prediction:\n";
        std::cout << "Estimated Crop Yield: " 
                  << std::fixed << std::setprecision(2) 
                  << predictedYield << " tons\n";
    }

    // Recommend irrigation based on soil moisture and crop water needs
    void recommendIrrigation() {
        std::cout << "\n----- IRRIGATION RECOMMENDATION -----\n";
        std::cout << "Enter Crop's Water Requirement (liters/acre) [Number > 0]: ";
        while (true) {
            std::cin >> cropWaterNeed;
            if (cropWaterNeed > 0) break;
            std::cout << "Invalid input. Please enter a positive number for crop water requirement: ";
        }

        double totalWaterNeed = cropWaterNeed * farmSize;
        std::cout << "\nIrrigation Plan:\n";
        std::cout << "Total Water Needed: " 
                  << std::fixed << std::setprecision(2) 
                  << totalWaterNeed << " liters\n";

        if (soilMoisture < 30) {
            std::cout << "CRITICAL: Immediate irrigation required!\n";
        } else {
            std::cout << "Irrigation can be scheduled optimally.\n";
        }
    }

    // Provide fertilizer guidance based on current levels
    void provideFertilizerGuidance() {
        std::cout << "\n----- FERTILIZER GUIDANCE -----\n";
        std::cout << "Enter Current Fertilizer Level [0 - 100]: ";
        while (true) {
            std::cin >> fertilizer;
            if (fertilizer >= MIN_SOIL_MOISTURE && fertilizer <= MAX_SOIL_MOISTURE) break;
            std::cout << "Invalid input. Please enter a valid fertilizer level (0-100): ";
        }

        std::cout << "\nFertilizer Recommendation:\n";
        if (fertilizer < 20) {
            std::cout << "LOW Nutrient Level\n";
            std::cout << "Recommendation: Apply complete fertilizer mix.\n";
        } else if (fertilizer >= 20 && fertilizer <= 50) {
            std::cout << "MODERATE Nutrient Level\n";
            std::cout << "Recommendation: Targeted nutrient supplementation.\n";
        } else {
            std::cout << "OPTIMAL Nutrient Level\n";
            std::cout << "Current fertilization is sufficient.\n";
        }
    }

    // Analyze market prices and suggest optimal selling time
    void analyzeMarketPrices() {
        std::cout << "\n----- MARKET PRICE ANALYSIS -----\n";
        std::cout << "Enter Current Market Price (per ton) [Number > 0]: ";
        while (true) {
            std::cin >> marketPrice;
            if (marketPrice > MIN_MARKET_PRICE) break;
            std::cout << "Invalid input. Please enter a positive market price: ";
        }

        std::cout << "\nMarket Price Analysis:\n";
        if (marketPrice < 100) {
            std::cout << "Warning: Low market price. Consider waiting to sell.\n";
        } else if (marketPrice >= 100 && marketPrice <= 200) {
            std::cout << "Market price is stable. Good time to sell.\n";
        } else {
            std::cout << "High market price! It's a great time to sell!\n";
        }
    }

    // Generate a comprehensive farm report with all the data
    void generateFarmReport() {
        std::cout << "\n===== COMPREHENSIVE FARM REPORT =====\n";
        std::cout << "Farm Size: " << farmSize << " acres\n";
        std::cout << "Crop Type: " << cropType << "\n";
        std::cout << "Soil Moisture: " << soilMoisture << "%\n";
        std::cout << "Temperature: " << temperature << "°C\n";
        std::cout << "Rainfall: " << rainfall << " mm\n";
        std::cout << "Fertilizer Level: " << fertilizer << "\n";
        std::cout << "Current Market Price: " << marketPrice << " per ton\n";
    }
};

int main() {
    AgricultureMonitoringSystem farmSystem;
    farmSystem.runSystem();
    return 0;
}