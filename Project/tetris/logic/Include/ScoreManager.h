#pragma once
#include <vector>
#include <string>

struct ScoreRecord {
    int score;
    std::string timeStr; // "MM:SS"
    std::string date;    // "DD.MM.YYYY"
};

class ScoreManager {
public:
    ScoreManager(const std::string& filename = "scores.txt");
    ~ScoreManager(); // закрыть файл, если нужно

    void load();
    void save();
    bool addIfHighScore(int score, const std::string& timeStr);
    const std::vector<ScoreRecord>& getTopScores() const { return topScores; }
    bool isHighScore(int score) const;

private:
    std::string filename;
    std::vector<ScoreRecord> topScores;

    void sortAndTrim();
    std::string getCurrentDate() const;
};
