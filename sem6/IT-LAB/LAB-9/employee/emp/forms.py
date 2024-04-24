from django import forms
from .models import works, lives

class workForm(forms.ModelForm):
    
    class Meta:
        model = works
        fields = ("name", "company", "sal")

class livesForm(forms.ModelForm):
    
    class Meta:
        model = lives
        fields = ("name","street", "state")
