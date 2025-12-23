using Microsoft.Win32;
using System;
using System.Drawing;
using System.Reflection.Emit;
using System.Windows.Forms;

namespace работа_4_2_шари
{
    public partial class Form1 : Form
    {
        private const string RegistryPath = @"Software\MyAppSettings";

        public Form1()
        {
            InitializeComponent();
            LoadSettings();
        }

        private void LoadSettings()
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
                            txtColor.Text = color;
                            txtSubject.Text = subject;
                            ApplyColorToForm(color);
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка загрузки настроек: {ex.Message}", "Ошибка",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void ApplyColorToForm(string color)
        {
            var colorMap = new System.Collections.Generic.Dictionary<string, Color>
            {
                ["red"] = Color.DarkRed,
                ["blue"] = Color.DarkBlue,
                ["green"] = Color.DarkGreen,
                ["yellow"] = Color.Yellow,
                ["white"] = Color.White
            };

            if (colorMap.TryGetValue(color.ToLower(), out var selectedColor))
            {
                this.BackColor = selectedColor;

                // Меняем цвет текста для лучшей читаемости
                if (color.ToLower() == "yellow" || color.ToLower() == "white")
                {
                    txtColor.ForeColor = Color.Black;
                    txtSubject.ForeColor = Color.Black;
                    label1.ForeColor = Color.Black;
                    label2.ForeColor = Color.Black;
                }
                else
                {
                    txtColor.ForeColor = Color.White;
                    txtSubject.ForeColor = Color.White;
                    label1.ForeColor = Color.White;
                    label2.ForeColor = Color.White;
                }
            }
        }

        private void btnSave_Click(object sender, EventArgs e)
        {
            string color = txtColor.Text;
            string subject = txtSubject.Text;

            if (string.IsNullOrEmpty(color) || string.IsNullOrEmpty(subject))
            {
                MessageBox.Show("Пожалуйста, заполните все поля!", "Предупреждение",
                    MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            try
            {
                using (RegistryKey key = Registry.CurrentUser.CreateSubKey(RegistryPath))
                {
                    key.SetValue("Color", color);
                    key.SetValue("Subject", subject);
                }

                ApplyColorToForm(color);
                MessageBox.Show("Настройки сохранены в реестре!", "Успех",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка сохранения: {ex.Message}", "Ошибка",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnLoad_Click(object sender, EventArgs e)
        {
            LoadSettings();
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            try
            {
                Registry.CurrentUser.DeleteSubKeyTree(RegistryPath, false);
                MessageBox.Show("Настройки удалены из реестра!", "Успех",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);

                txtColor.Text = "";
                txtSubject.Text = "";
                this.BackColor = SystemColors.Control;
                txtColor.ForeColor = SystemColors.WindowText;
                txtSubject.ForeColor = SystemColors.WindowText;
                label1.ForeColor = SystemColors.WindowText;
                label2.ForeColor = SystemColors.WindowText;
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка удаления: {ex.Message}", "Ошибка",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
    }
}
