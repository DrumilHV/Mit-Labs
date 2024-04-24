from django.shortcuts import render
from .forms import workForm, livesForm
from django.http import HttpResponseRedirect
from .models import works, lives
# Create your views here.

def createEmp(request):
    worker = works.objects.all()
    liv = lives.objects.all()
    if(request.method == 'POST'):
        work_form = workForm(request.POST)
        lives_form = livesForm(request.POST)
        if work_form.is_valid() and lives_form.is_valid():
            work_form.save()
            lives_form.save()
            return HttpResponseRedirect('/create/')
    else:
        work_form = workForm()
        lives_form = livesForm()

    return render(request, 'insertData.html', {'lives_form': lives_form, 'work_form': work_form, 'works': worker, 'lives':liv})
    
def retrieveEmp(request):
    if request.method == 'POST':
        company_name = request.POST.get('company')
        people = works.objects.filter(company=company_name).values_list('name', flat=True)
        cities = lives.objects.filter(name__in=people).values_list('state', flat=True)
        result = zip(people, cities)
        return render(request, 'retrieve_data.html', {'result': result})
    return render(request, 'retrieve_data.html')
            
        
        
# from django.shortcuts import render
# from .forms import workForm, livesForm
# from django.http import HttpResponseRedirect

# def createEmp(request):
#     if request.method == 'POST':
#         work_form = workForm(request.POST)
#         lives_form = livesForm(request.POST)
#         if work_form.is_valid() and lives_form.is_valid():
#             work_form.save()
#             lives_form.save()
#             return HttpResponseRedirect('/retrieve/')
#     else:
#         work_form = workForm()  # Move form initialization outside the if block
#         lives_form = livesForm()  # Move form initialization outside the if block

#     return render(request, 'insertData.html', {'lives_form': lives_form, 'work_form': work_form})

# def retrieveEmp(request):
#     if request.method == 'POST':
#         company_name = request.POST.get('company_name')
#         people = Works.objects.filter(company_name=company_name).values_list('person_name', flat=True)
#         cities = Lives.objects.filter(person_name__in=people).values_list('state', flat=True)
#         result = zip(people, cities)
#         return render(request, 'retrieve_data.html', {'result': result})
#     return render(request, 'retrieve_data.html')
