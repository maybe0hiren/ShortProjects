#include <iostream>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <limits>

/* ───────────── ANSI Colors ───────────── */
const std::string RESET  = "\033[0m";
const std::string BOLD   = "\033[1m";
const std::string DIM    = "\033[2m";

const std::string RED    = "\033[31m";
const std::string GREEN  = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE   = "\033[34m";
const std::string CYAN   = "\033[36m";

/* ───────────── UI Helpers ───────────── */
void printBanner() {
    std::cout << CYAN << BOLD;
    std::cout << "╭──────────────────────────────────────╮\n";
    std::cout << "│          KnowThyRepo  CLI            │\n";
    std::cout << "│    Ask questions about GitHub repos  │\n";
    std::cout << "╰──────────────────────────────────────╯\n";
    std::cout << RESET << std::endl;
}

void separator() {
    std::cout << DIM
              << "────────────────────────────────────────"
              << RESET << std::endl;
}

/* ───────────── Execute Shell Command ───────────── */
std::string executeCommand(const std::string &command) {
    std::string result;
    constexpr size_t BUFFER_SIZE = 4096;
    char buffer[BUFFER_SIZE];

    std::unique_ptr<FILE, int (*)(FILE*)> pipe(
        popen(command.c_str(), "r"), pclose
    );

    if (!pipe) {
        throw std::runtime_error("popen() failed");
    }

    while (fgets(buffer, BUFFER_SIZE, pipe.get()) != nullptr) {
        result += buffer;
    }

    return result;
}

/* ───────────── Trim Whitespace ───────────── */
std::string trimWhitespace(const std::string& s) {
    const std::string whitespace = " \n\r\t";
    size_t start = s.find_first_not_of(whitespace);
    size_t end   = s.find_last_not_of(whitespace);

    if (start == std::string::npos) return "";
    return s.substr(start, end - start + 1);
}

/* ───────────── Main ───────────── */
int main() {
    executeCommand("clear");

    std::string key = "ASKDHAKSHDJKAHJSDH";
    std::string repoLink;
    std::string question;

    printBanner();

    std::cout << BOLD << "Repository URL" << RESET << ": ";
    std::cin >> repoLink;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    separator();
    std::cout << DIM << "Type your question and press ENTER\n";
    std::cout << DIM << "Type EXIT to quit\n" << RESET;
    separator();

    while (true) {
        std::cout << GREEN << BOLD << "❯ Question" << RESET << ": ";
        std::getline(std::cin, question);

        if (question == "EXIT") {
            std::cout << YELLOW << "\nGoodbye 👋\n" << RESET;
            break;
        }

        std::cout << CYAN << DIM << "⏳ Thinking...\n" << RESET;

        std::string curlCommand =
            "curl -s -X POST https://knowthyrepo.onrender.com/knowThyRepo "
            "-H \"Authorization: Bearer " + key + "\" "
            "-H \"Content-Type: application/json\" "
            "-d \"{\\\"repoLink\\\":\\\"" + repoLink +
            "\\\",\\\"question\\\":\\\"" + question + "\\\"}\"";

        try {
            std::string output = executeCommand(curlCommand);
            output = trimWhitespace(output);

            const std::string prefix = R"({"answer":")";
            const std::string suffix = R"("})";

            if (output.size() >= prefix.size() + suffix.size() &&
                output.compare(0, prefix.size(), prefix) == 0 &&
                output.compare(output.size() - suffix.size(), suffix.size(), suffix) == 0) {

                output = output.substr(
                    prefix.size(),
                    output.size() - prefix.size() - suffix.size()
                );
            }

            separator();
            std::cout << BLUE << BOLD << "📄 Answer\n" << RESET;
            std::cout << output << std::endl;
            separator();

        } catch (const std::exception &e) {
            std::cout << RED << "Error: " << e.what() << RESET << std::endl;
        }
    }

    return 0;
}
