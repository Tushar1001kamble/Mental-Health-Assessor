#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Function prototypes
void askAnxietyQuestions(int&, const string&);
void askDepressiveQuestions(int&, const string&);
void askStressRelatedQuestions(int&, const string&);
void askSubstanceUseQuestions(int&, const string&);
void askEatingDisorderQuestions(int&, const string&);

bool registerUser();
bool loginUser();

int main() {
    // Register or login user
    if (!loginUser() && !registerUser()) {
        cout << "Exiting program." << endl;
        return 0;
    }

    int problemChoice;
    int yesCount = 0;

    // Display problem options and prompt user to select one
    cout << "Select a problem from the following list:" << endl;
    cout << "1. Anxiety Disorders" << endl;
    cout << "2. Depressive Disorders" << endl;
    cout << "3. Stress-Related Disorders" << endl;
    cout << "4. Substance Use Disorders" << endl;
    cout << "5. Eating Disorders" << endl;
    cout << "Enter the corresponding number: ";
    cin >> problemChoice;

    string username; // User's username
    // Ask for username again if not logged in
    if (!loginUser()) {
        cout << "Invalid username or password." << endl;
        return 0;
    }

    // Call the appropriate function based on user's problem choice
    switch (problemChoice) {
        case 1:
            cout << "You selected Anxiety Disorders." << endl;
            askAnxietyQuestions(yesCount, username);
            break;
        case 2:
            cout << "You selected Depressive Disorders." << endl;
            askDepressiveQuestions(yesCount, username);
            break;
        case 3:
            cout << "You selected Stress-Related Disorders." << endl;
            askStressRelatedQuestions(yesCount, username);
            break;
        case 4:
            cout << "You selected Substance Use Disorders." << endl;
            askSubstanceUseQuestions(yesCount, username);
            break;
        case 5:
            cout << "You selected Eating Disorders." << endl;
            askEatingDisorderQuestions(yesCount, username);
            break;
        default:
            cout << "Invalid choice. Please select a number between 1 and 5." << endl;
            return 0;
    }

    // Calculate percentage of "yes" answers
    double percentage = static_cast<double>(yesCount) / 10 * 100;

    // Display the percentage score
    cout << "Your score: " << fixed << setprecision(2) << percentage << "%" << endl;

    // Provide feedback based on the number of "yes" answers
    if (percentage >= 50) {
        cout << "While your score is above 50%, it's important to address any underlying issues with the help of a healthcare professional." << endl;
    } else {
        cout << "It appears that your symptoms may be significant. Seeking guidance from a healthcare provider is recommended." << endl;
        // Provide primary solutions based on the selected problem (you can add your specific recommendations here)
    }

    // Writing data to a file
    ofstream file(username + "_data.txt", ios::app);
    if (file.is_open()) {
        file << "Problem Choice: " << problemChoice << endl;
        file << "Score: " << percentage << "%" << endl;
        file << "---------------------------------------------" << endl;
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }

    return 0;
}

// Function to register a new user
bool registerUser() {
    string username, password;
    cout << "You need to register first." << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (file) {
        cout << "Username already exists. Please try again." << endl;
        return false;
    }

    ofstream outfile(username + ".txt");
    if (outfile) {
        outfile << username << " " << password << endl;
        cout << "Registration successful. You can now log in." << endl;
        return true;
    } else {
        cout << "Failed to create user file." << endl;
        return false;
    }
}

// Function to log in an existing user
bool loginUser() {
    string username, password, storedPassword;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    if (!file) {
        cout << "User not found. Please register first." << endl;
        return false;
    }

    file >> storedPassword;
    if (storedPassword != password) {
        cout << "Incorrect password." << endl;
        return false;
    }

    cout << "Login successful." << endl;
    return true;
}

// Problem functions definitions...
//1st problem
void askAnxietyQuestions(int& count, const string& username) {
    string answer;

    cout << "Anxiety Disorder Questions:" << endl;
    cout << "1. Do you often feel excessively worried or anxious about various aspects of your life?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "2. Do you experience frequent panic attacks characterized by sudden and intense fear or discomfort?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "3. Are you constantly on edge or easily startled by minor stimuli?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "4. Do you avoid social situations or specific places or activities due to fear or anxiety?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "5. Do you have difficulty controlling your worries or irrational fears?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "6. Are you frequently tense or experience muscle tension, trembling, or sweating?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "7. Do you often experience racing thoughts or have difficulty concentrating?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "8. Do you frequently experience physical symptoms such as shortness of breath, rapid heartbeat, or stomach discomfort?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "9. Do you have difficulty falling or staying asleep due to anxious thoughts or worries?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "10. Do your anxiety symptoms significantly interfere with your daily life or activities?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }
}


//2nd problem
void askDepressiveQuestions(int& count, const string& username) {
    string answer;

    cout << "Depressive Disorder Questions:" << endl;
    cout << "1. Do you often feel sad, hopeless, or empty for most of the day, nearly every day?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "2. Have you lost interest or pleasure in activities that you used to enjoy?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "3. Do you experience significant changes in appetite or weight, such as overeating or loss of appetite?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "4. Do you have difficulty sleeping, such as trouble falling asleep, staying asleep, or sleeping too much?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "5. Do you feel fatigued or have low energy levels most days?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "6. Do you experience feelings of worthlessness or excessive guilt?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "7. Do you have difficulty concentrating, making decisions, or remembering things?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "8. Do you have recurring thoughts of death or suicide, or have you made suicide attempts?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "9. Do you experience physical symptoms such as aches, pains, or digestive issues without a clear medical cause?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "10. Do your depressive symptoms significantly interfere with your daily life or functioning?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }
}



//3rd problem
void askStressRelatedQuestions(int& count, const string& username) {
    string answer;

    cout << "Stress-Related Disorder Questions:" << endl;
    cout << "1. Have you experienced or witnessed a traumatic event that continues to affect you emotionally?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "2. Do you frequently experience intrusive memories, flashbacks, or nightmares related to the traumatic event?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "3. Do you actively avoid reminders of the traumatic event, such as places, people, or activities?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "4. Do you feel constantly on guard, easily startled, or hypervigilant?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "5. Do you have difficulty concentrating or experiencing memory problems?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "6. Do you feel emotionally numb or disconnected from others?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "7. Do you experience intense feelings of fear, anger, or irritability?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "8. Do you have difficulty sleeping, experiencing insomnia, or restless sleep?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "9. Do you engage in risky behaviors or have difficulty controlling impulses?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "10. Do your stress-related symptoms significantly interfere with your daily life or functioning?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }
}


//4th problem
void askSubstanceUseQuestions(int& count, const string& username) {
    string answer;

    cout << "Substance Use Disorder Questions:" << endl;
    cout << "1. Do you frequently use alcohol, drugs, or other substances to cope with stress or emotional pain?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "2. Have you experienced cravings or strong urges to use substances, especially when stressed or upset?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "3. Have you tried unsuccessfully to cut down or control your substance use?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "4. Do you need to use increasing amounts of a substance to achieve the desired effect (tolerance)?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "5. Do you experience withdrawal symptoms when you stop using a substance or reduce your intake?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "6. Have you continued to use substances despite experiencing negative consequences in your life (e.g., health problems, relationship issues, legal trouble)?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "7. Do you spend a significant amount of time obtaining, using, or recovering from the effects of substances?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "8. Have you neglected responsibilities or important activities in favor of substance use?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "9. Have you experienced disruptions in your relationships or social life due to substance use?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "10. Do you want to cut down or quit using substances but find it difficult to do so?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }
}



//5th problem
void askEatingDisorderQuestions(int& count, const string& username) {
    string answer;

    cout << "Eating Disorder Questions:" << endl;
    cout << "1. Do you have an intense fear of gaining weight or becoming fat, even if you are underweight?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "2. Do you engage in restrictive eating behaviors, such as severely limiting food intake or avoiding certain foods?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "3. Do you have a distorted body image, perceiving yourself as overweight even when you are underweight?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "4. Do you frequently weigh yourself or obsessively monitor your body shape or size?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "5. Do you experience episodes of binge eating, consuming large amounts of food in a short period while feeling out of control?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "6. Do you engage in compensatory behaviors to control your weight, such as self-induced vomiting, misuse of laxatives, or excessive exercise?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "7. Do you experience guilt, shame, or disgust after binge eating episodes or engaging in compensatory behaviors?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "8. Do you hide or lie about your eating habits or behaviors?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "9. Have you experienced physical complications related to your eating behaviors, such as gastrointestinal problems or changes in menstrual cycles?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }

    cout << "10. Do your eating disorder symptoms significantly interfere with your daily life or functioning?" << endl;
    cout << "Yes/No? ";
    cin >> answer;
    if (answer == "yes") {
        ++count;
    }
}