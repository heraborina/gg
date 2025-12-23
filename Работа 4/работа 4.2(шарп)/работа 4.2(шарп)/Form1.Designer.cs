using Microsoft.Win32;
using System;
using System.Collections.Generic;

class SettingsManager
{
    private const string RegistryPath = @"Software\MyAppSettings";

    // Сохранить настройки в реестр
    public static bool SaveSettings(string color, string subject)
    {
        try
        {
            using (RegistryKey key = Registry.CurrentUser.CreateSubKey(RegistryPath))
            {
                key.SetValue("Color", color);
                key.SetValue("Subject", subject);
            }
            return true;
        }
        catch
        {
            return false;
        }
    }

    // Загрузить настройки из реестра
    public static (string color, string subject, bool success) LoadSettings()
    {
        try
        {
            using (RegistryKey key = Registry.CurrentUser.OpenSubKey(RegistryPath))
            {
                if (key != null)
                {
                    string color = key.GetValue("Color") as string ?? "";
                    string subject = key.GetValue("Subject") as string ?? "";

                    if (!string.IsNullOrEmpty(color) && !string.IsNullOrEmpty(subject))
                    {
                        return (color, subject, true);
                    }
                }
            }
        }
        catch { }

        return ("", "", false);
    }
}

class Program
{
    static void ApplyConsoleColor(string color)
    {
        var colorMap = new Dictionary<string, (ConsoleColor bg, ConsoleColor fg)>
        {
            ["red"] = (ConsoleColor.DarkRed, ConsoleColor.White),
            ["blue"] = (ConsoleColor.DarkBlue, ConsoleColor.White),
            ["green"] = (ConsoleColor.DarkGreen, ConsoleColor.White),
            ["yellow"] = (ConsoleColor.DarkYellow, ConsoleColor.Black),
            ["white"] = (ConsoleColor.White, ConsoleColor.Black)
        };

        if (colorMap.TryGetValue(color.ToLower(), out var colors))
        {
            Console.BackgroundColor = colors.bg;
            Console.ForegroundColor = colors.fg;
            Console.Clear();
        }
        else
        {
            Console.ResetColor();
            Console.Clear();
        }
    }

    static void main()
    {
        Console.OutputEncoding = System.Text.Encoding.UTF8;

        Console.WriteLine("=== Настройки пользователя ===\n");
        Console.WriteLine(                                                                                                                                                      
        // Загрузка существующих настроек
        var (color, subject, hasSettings) = SettingsManager.LoadSettings();

        if (hasSettings)
        {
            ApplyConsoleColor(color);

            Console.WriteLine($"Текущий цвет: {color}");
            Console.WriteLine($"Текущий предмет: {subject}");

            Console.Write("\nИзменить настройки? (y/N): ");
            if (Console.ReadKey().Key == ConsoleKey.Y)
            {
                Console.WriteLine();
                GetNewSettings(ref color, ref subject);
            }
        }
        else
        {
            Console.WriteLine("Настройки не найдены. Создание новых...");
            GetNewSettings(ref color, ref subject);
        }

        Console.WriteLine("\n=== Текущие настройки ===");
        Console.WriteLine($"Цвет: {color}");
        Console.WriteLine($"Предмет: {subject}");

        Console.WriteLine("\nНажмите любую клавишу для выхода...");
        Console.ReadKey();
    }

    static void GetNewSettings(ref string color, ref string subject)
    {
        Console.Write("Введите цвет (red/blue/green/yellow/white): ");
        color = Console.ReadLine();

        Console.Write("Введите любимый предмет: ");
        subject = Console.ReadLine();

        if (SettingsManager.SaveSettings(color, subject))
        {
            ApplyConsoleColor(color);
            Console.WriteLine("\n✓ Настройки сохранены в реестре!");
        }
        else
        {
            Console.WriteLine("\n✗ Ошибка сохранения в реестр!");
        }
    }
}
