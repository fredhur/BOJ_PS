#include <cstdio>
struct Date
{
    int year;
    int month;
    int day;
};
class Birth
{
public:
    Birth() = default;
    Birth(Date &&birth, Date &&cur)
    {
        birth_ = birth;
        cur_ = cur;
    }
    ~Birth() = default;
    int ManAge() const
    {
        int age = cur_.year - birth_.year;
        if (cur_.month < birth_.month)
        {
            age--;
        }
        if (cur_.month == birth_.month)
        {
            if (cur_.day < birth_.day)
            {
                age--;
            }
        }
        return age;
    }
    int senAge() const
    {
        return cur_.year - birth_.year + 1;
    }
    int yeonAge() const
    {
        return cur_.year - birth_.year;
    }

private:
    Date birth_;
    Date cur_;
};
int main()
{
    int y1, m1, d1;
    int y2, m2, d2;
    scanf("%d %d %d", &y1, &m1, &d1);
    scanf(" %d %d %d", &y2, &m2, &d2);
    Birth birth(Date{y1, m1, d1}, Date{y2, m2, d2});

    printf("%d\n", birth.ManAge());
    printf("%d\n", birth.senAge());
    printf("%d\n", birth.yeonAge());
}