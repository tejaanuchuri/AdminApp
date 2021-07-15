// CHomePageDlg.cpp : implementation file
//

#include "pch.h"
#include "Admin.h"
#include "CHomePageDlg.h"
#include "afxdialogex.h"


#include "odbcinst.h"
#include "afxdb.h"

// CHomePageDlg dialog

IMPLEMENT_DYNAMIC(CHomePageDlg, CDialog)

CHomePageDlg::CHomePageDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_ADMIN_HOME_PAGE, pParent)
	, emp_title(_T(""))
	, emp_firstname(_T(""))
	, emp_age(_T(""))
	, emp_gender(_T(""))
	, emp_email(_T(""))
	, emp_datebirth(COleDateTime::GetCurrentTime())
	, emp_phonenumber(_T(""))
	, emp_address(_T(""))
	, emp_salary(_T(""))
	, emp_jobtitle(_T(""))
	, uemp_no(_T(""))
	, change_operation(_T(""))
	, UChooseField(_T(""))
	, DEmployeeNumber(_T(""))
	, CChooseFieldSearch(_T(""))
	, CEmpSearchDetails(_T(""))
	, emp_lastname(_T(""))
	, emp_HireDate(COleDateTime::GetCurrentTime())
	, employee_hiredate(COleDateTime::GetCurrentTime())
	, Update_Field_Value(_T(""))
	, UpdateDate(COleDateTime::GetCurrentTime())
{

}

CHomePageDlg::~CHomePageDlg()
{
}

void CHomePageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_FETCH_ALL_RECORDS, emp_list);
	DDX_CBString(pDX, IDC_COMBO_TITLE, emp_title);
	DDX_Text(pDX, IDC_EDIT_FIRST_NAME, emp_firstname);
	DDX_Text(pDX, IDC_EDIT_AGE, emp_age);
	DDX_CBString(pDX, IDC_COMBO_GENDER, emp_gender);
	DDX_Text(pDX, IDC_EDIT_EMAIL, emp_email);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR1_DATE_BIRTH, emp_datebirth);
	DDX_Text(pDX, IDC_EDIT_PHONE_NUMBER, emp_phonenumber);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, emp_address);
	DDX_Text(pDX, IDC_EDIT_SALARY, emp_salary);
	DDX_CBString(pDX, IDC_COMBO_JOB_TITLE, emp_jobtitle);
	DDX_Control(pDX, IDC_COMBO_TITLE, cemp_title);
	DDX_Control(pDX, IDC_STATIC_EMP_TITLE, c_title);
	DDX_Text(pDX, IDC_EDIT_EMP_NO, uemp_no);
	DDX_CBString(pDX, IDC_COMBO_SWITCHING_OPERATIONS, change_operation);
	DDX_Control(pDX, IDC_STATIC_TITLE, cinsert_title);
	DDX_Control(pDX, IDC_STATIC_AGE, CSAge);
	DDX_Control(pDX, IDC_EDIT_AGE, CAge);
	DDX_Control(pDX, IDC_STATIC_FIRST_NAME, CSFirstName);
	DDX_Control(pDX, IDC_EDIT_FIRST_NAME, CFirstName);
	DDX_Control(pDX, IDC_STATIC_LAST_NAME, CSLastName);
	DDX_Control(pDX, IDC_EDIT_LAST_NAME, CLastName);
	DDX_Control(pDX, IDC_STATIC_GENDER, CSGender);
	DDX_Control(pDX, IDC_COMBO_GENDER, CGender);
	DDX_Control(pDX, IDC_STATIC_EMAIL, CSEmail);
	DDX_Control(pDX, IDC_EDIT_EMAIL, CEmail);
	DDX_Control(pDX, IDC_STATIC_PHONE_NUMBER, CSPhoneNumber);
	DDX_Control(pDX, IDC_EDIT_PHONE_NUMBER, CPhoneNumber);
	DDX_Control(pDX, IDC_STATIC_ADDRESS, CSAddress);
	DDX_Control(pDX, IDC_EDIT_ADDRESS, CAddress);
	DDX_Control(pDX, IDC_STATIC_DATE_OF_BIRTH, CSDateBirth);
	DDX_Control(pDX, IDC_MONTHCALENDAR1_DATE_BIRTH, CBirthDate);
	DDX_Control(pDX, IDC_STATIC_JOB_TITLE, CSJobTitle);
	DDX_Control(pDX, IDC_COMBO_JOB_TITLE, CJobTitle);
	DDX_Control(pDX, IDC_STATIC_SALARY, CSSalary);
	DDX_Control(pDX, IDC_EDIT_SALARY, CSalary);
	DDX_Control(pDX, IDC_STATIC_HIREDATE, CSHireDate);
	DDX_Control(pDX, IDC_BUTTON_INSERT_EMPLOYEE, Cinsert);
	DDX_Control(pDX, IDC_STATIC_UPDATE_RECORD, CSUpdateRecord);
	DDX_Control(pDX, IDC_STATIC_EMP_NO, CSEmpNo);
	DDX_Control(pDX, IDC_EDIT_EMP_NO, CEmpNumber);
	DDX_Control(pDX, IDC_STATIC_CHOOSE_FILED, CSChooseField);
	DDX_Control(pDX, IDC_COMBO_CHOOSE_FIELD, CChooseField);
	DDX_CBString(pDX, IDC_COMBO_CHOOSE_FIELD, UChooseField);
	DDX_Control(pDX, IDC_STATIC_UPDATE_FILED, CDUpdataField);
	DDX_Control(pDX, IDC_EDIT_UPDATE_FIELD, CUpdateField);
	DDX_Control(pDX, IDC_BUTTON_UPDATE_EMPLOYEE_RECORD, CBUpdate);
	DDX_Control(pDX, IDC_STATIC_DELETE_EMPLOYEE_RECORD, CSDeleteEmployee);
	DDX_Control(pDX, IDC_STATIC_EMPLOYEE_NUMBER, CSEnterEmployeeNumber);
	DDX_Text(pDX, IDC_EDIT_ENTER_EMPLOYEE_NUMBER, DEmployeeNumber);
	DDX_Control(pDX, IDC_BUTTON_DELETE_EMPLOYEE_RECORD, CBDelete);
	DDX_Control(pDX, IDC_EDIT_ENTER_EMPLOYEE_NUMBER, CSEnterEmpNumber);
	DDX_Control(pDX, IDC_STATIC_SEARCH_EMPLOYEE_RECORD, CSSearchEmpRecord);
	DDX_Control(pDX, IDC_STATIC_CHOOSE_THE_FIELD, CSChooseFieldSearch);
	DDX_CBString(pDX, IDC_COMBO_CHOOSE_FIELD_TO_SEARCH, CChooseFieldSearch);
	DDX_Control(pDX, IDC_STATIC_ENTER_EMP_DETAILS, CSEnterEmployeeDetails);
	DDX_Control(pDX, IDC_EDIT_ENTER_SEARCH_VALUe, CEnterEmployeeDetails);
	DDX_Text(pDX, IDC_EDIT_ENTER_SEARCH_VALUe, CEmpSearchDetails);
	DDX_Control(pDX, IDC_BUTTON_SEARCH_EMPLOYEE_RECORD, CBSearch);
	DDX_Control(pDX, IDC_COMBO_CHOOSE_FIELD_TO_SEARCH, CChooseFeildSearchValue);
	DDX_Control(pDX, IDC_BUTTON_FETCH_RECORDS, CBFetchSearch);
	DDX_Text(pDX, IDC_EDIT_LAST_NAME, emp_lastname);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR_EMPLOYEE_HIREDATE, employee_hiredate);
	DDX_Text(pDX, IDC_EDIT_UPDATE_FIELD, Update_Field_Value);
	DDX_Control(pDX, IDC_MONTHCALENDAR_UPDATE_DATE, CUpdateDate);
	DDX_MonthCalCtrl(pDX, IDC_MONTHCALENDAR_UPDATE_DATE, UpdateDate);
	DDX_Control(pDX, IDC_LIST_SEARCH_LIST, m_Search_list);
}


BEGIN_MESSAGE_MAP(CHomePageDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_FETCH_RECORDS, &CHomePageDlg::OnBnClickedButtonFetchRecords)
	ON_BN_CLICKED(IDC_BUTTON_SWITCHING_OPERATONS, &CHomePageDlg::OnBnClickedButtonSwitchingOperatons)

	ON_BN_CLICKED(IDC_BUTTON_INSERT_EMPLOYEE, &CHomePageDlg::OnBnClickedButtonInsertEmployee)
	ON_BN_CLICKED(IDC_BUTTON_DELETE_EMPLOYEE_RECORD, &CHomePageDlg::OnBnClickedButtonDeleteEmployeeRecord)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH_EMPLOYEE_RECORD, &CHomePageDlg::OnBnClickedButtonSearchEmployeeRecord)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE_EMPLOYEE_RECORD, &CHomePageDlg::OnBnClickedButtonUpdateEmployeeRecord)
	ON_CBN_SELCHANGE(IDC_COMBO_CHOOSE_FIELD, &CHomePageDlg::OnCbnSelchangeComboChooseField)
	ON_CBN_DROPDOWN(IDC_COMBO_CHOOSE_FIELD, &CHomePageDlg::OnCbnDropdownComboChooseField)
	ON_CBN_EDITUPDATE(IDC_COMBO_CHOOSE_FIELD, &CHomePageDlg::OnCbnEditupdateComboChooseField)
	ON_CBN_EDITCHANGE(IDC_COMBO_CHOOSE_FIELD, &CHomePageDlg::OnCbnEditchangeComboChooseField)
	ON_STN_CLICKED(IDC_STATIC_UPDATE_FILED, &CHomePageDlg::OnStnClickedStaticUpdateFiled)
	ON_BN_CLICKED(IDC_BUTTON_SET_THE_COLUMN, &CHomePageDlg::OnBnClickedButtonSetTheColumn)
	ON_STN_CLICKED(IDC_STATIC_ENTER_EMP_DETAILS, &CHomePageDlg::OnStnClickedStaticEnterEmpDetails)
END_MESSAGE_MAP()


// CHomePageDlg message handlers




void CHomePageDlg::OnBnClickedButtonFetchRecords()
{
	UpdateData(TRUE);
	emp_list.EnableWindow(TRUE);

}


BOOL CHomePageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	/*cinsert_title.EnableWindow(FALSE);
	c_title.EnableWindow(FALSE);
	cemp_title.EnableWindow(FALSE);
	CSAge.EnableWindow(FALSE);
	CAge.EnableWindow(FALSE);
	CSFirstName.EnableWindow(FALSE);
	CFirstName.EnableWindow(FALSE);
	CLastName.EnableWindow(FALSE);
	CSLastName.EnableWindow(FALSE);
	CSGender.EnableWindow(FALSE);
	CGender.EnableWindow(FALSE);
	CSEmail.EnableWindow(FALSE);
	CEmail.EnableWindow(FALSE);
	CSPhoneNumber.EnableWindow(FALSE);
	CPhoneNumber.EnableWindow(FALSE);
	CSAddress.EnableWindow(FALSE);
	CAddress.EnableWindow(FALSE);
	CSDateBirth.EnableWindow(FALSE);
	CBirthDate.EnableWindow(FALSE);
	CSJobTitle.EnableWindow(FALSE);
	CJobTitle.EnableWindow(FALSE);
	CSSalary.EnableWindow(FALSE);
	CSalary.EnableWindow(FALSE);
	CSHireDate.EnableWindow(FALSE);
	CHireDate.EnableWindow(FALSE);
	CSUpdateRecord.EnableWindow(FALSE);
	CSEmpNo.EnableWindow(FALSE);
	CEmpNumber.EnableWindow(FALSE);
	CSChooseField.EnableWindow(FALSE);
	CChooseField.EnableWindow(FALSE);
	CDUpdataField.EnableWindow(FALSE);
	CUpdateField.EnableWindow(FALSE);
	CBUpdate.EnableWindow(FALSE);
	CSDeleteEmployee.EnableWindow(FALSE);
	CSEnterEmployeeNumber.EnableWindow(FALSE);
	CSEnterEmpNumber.EnableWindow(FALSE);
	CBDelete.EnableWindow(FALSE);
	CSSearchEmpRecord.EnableWindow(FALSE);
	CSChooseFieldSearch.EnableWindow(FALSE);
	CChooseFeildSearchValue.EnableWindow(FALSE);
	CSEnterEmployeeDetails.EnableWindow(FALSE);
	CEnterEmployeeDetails.EnableWindow(FALSE);
	CBSearch.EnableWindow(FALSE);
	CBFetchSearch.EnableWindow(FALSE);
	Cinsert.EnableWindow(FALSE);*/

	GetDlgItem(IDC_STATIC_TITLE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_EMP_TITLE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO_TITLE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_AGE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_AGE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_FIRST_NAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_FIRST_NAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_LAST_NAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_LAST_NAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_GENDER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO_GENDER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_EMAIL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_EMAIL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_PHONE_NUMBER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_PHONE_NUMBER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_DATE_OF_BIRTH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MONTHCALENDAR1_DATE_BIRTH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_JOB_TITLE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO_JOB_TITLE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_SALARY)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_SALARY)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_HIREDATE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MONTHCALENDAR_EMPLOYEE_HIREDATE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_INSERT_EMPLOYEE)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_UPDATE_RECORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_EMP_NO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_EMP_NO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_CHOOSE_FILED)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO_CHOOSE_FIELD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_UPDATE_FILED)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_UPDATE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_SET_THE_COLUMN)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_ENTER_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_STATIC_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_CHOOSE_THE_FIELD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO_CHOOSE_FIELD_TO_SEARCH)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_ENTER_EMP_DETAILS)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_ENTER_SEARCH_VALUe)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_LIST_SEARCH_LIST)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_LIST_FETCH_ALL_RECORDS)->ShowWindow(SW_SHOW);
	emp_data_load();
	UpdateWindow();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
void CHomePageDlg::emp_data_load() {
	UpdateData(FALSE); // flow direction database -> ui

	CString e_id;
	CString e_age;
	CString e_title;
	CString e_firstname;
	CString e_lastname;
	CString e_gender;
	CString e_phonenumber;
	CString e_email;
	CString e_birthdate;
	CString e_address;
	CString e_jobtitle;
	CString e_salary;
	CString e_hiredate;

	CDatabase database;
	CString sDsn;
	CString SqlString;
	int iRec = 0;
	// Build ODBC connection string
	//sDsn.Format(_T("Driver={ODBC Driver 17 for SQL Server};Server=FYYP1N2;Dbq=C:\\Program Files\\Microsoft SQL Server\\MSSQL15.MSSQLSERVER\\MSSQL\\DATA\\AdminApp.mdf;Trusted_Connection=yes"));

	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\EmployeeDatabase.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		CRecordset recset(&database);
		database.Open(NULL,false,false,sDsn);
	SqlString = L"SELECT * FROM EmployeeTable";

	//AfxMessageBox(SqlString);
	//database.ExecuteSQL(SqlString);

	recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);
	m_ResetListControl();
	ListView_SetExtendedListViewStyle(emp_list, LVS_EX_GRIDLINES);
	emp_list.InsertColumn(
		0,              // Rank/order of item
		L"EmpID",          // Caption for this header
		LVCFMT_LEFT,    // Relative position of items under header
		100);           // Width of items under header

	emp_list.InsertColumn(1, L"Title", LVCFMT_CENTER, 80);
	emp_list.InsertColumn(2, L"Age", LVCFMT_LEFT, 100);
	emp_list.InsertColumn(3, L"FirstName", LVCFMT_CENTER, 80);
	emp_list.InsertColumn(4, L"LastName", LVCFMT_LEFT, 100);
	emp_list.InsertColumn(5, L"Gender", LVCFMT_CENTER, 80);
	emp_list.InsertColumn(6, L"MobilePhone", LVCFMT_LEFT, 100);
	emp_list.InsertColumn(7, L"EMail", LVCFMT_CENTER, 80);
	emp_list.InsertColumn(8, L"BirthDate", LVCFMT_LEFT, 100);
	emp_list.InsertColumn(9, L"Address", LVCFMT_CENTER, 80);
	emp_list.InsertColumn(10, L"JobTitle", LVCFMT_LEFT, 100);
	emp_list.InsertColumn(11, L"Salary", LVCFMT_CENTER, 80);
	emp_list.InsertColumn(12, L"HireDate", LVCFMT_LEFT, 100);

	while (!recset.IsEOF()) {
		// Copy each column into a variable
		recset.GetFieldValue(L"EmpID", e_id);
		recset.GetFieldValue(L"Title",e_title);
		recset.GetFieldValue(L"Age", e_age);
		recset.GetFieldValue(L"FirstName", e_firstname);
		recset.GetFieldValue(L"LastName", e_lastname);
		recset.GetFieldValue(L"Gender", e_gender);
		recset.GetFieldValue(L"MobilePhone", e_phonenumber);
		recset.GetFieldValue(L"EMail", e_email);
		recset.GetFieldValue(L"BirthDate", e_birthdate);
		recset.GetFieldValue(L"Address", e_address);
		recset.GetFieldValue(L"JobTitle", e_jobtitle);
		recset.GetFieldValue(L"Salary", e_salary);
		recset.GetFieldValue(L"Hiredate", e_hiredate);

		// Insert values into the list control
		iRec = emp_list.InsertItem(0, e_id, 0);
		emp_list.SetItemText(0, 1, e_title);
		emp_list.SetItemText(0, 2, e_age);
		emp_list.SetItemText(0, 3, e_firstname);
		emp_list.SetItemText(0, 4, e_lastname);
		emp_list.SetItemText(0, 5, e_gender);
		emp_list.SetItemText(0, 6, e_phonenumber);
		emp_list.SetItemText(0, 7, e_email);
		emp_list.SetItemText(0, 8, e_birthdate);
		emp_list.SetItemText(0, 9, e_address);
		emp_list.SetItemText(0, 10, e_jobtitle);
		emp_list.SetItemText(0, 11, e_salary);
		emp_list.SetItemText(0, 12, e_hiredate);

		// goto next record
		recset.MoveNext();
	}
	//MessageBox(L"Record Loaded sucessfully...!");
	// Close the database
	database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: " + e->m_strError);
	}
	END_CATCH;
}


void CHomePageDlg::OnBnClickedButtonSwitchingOperatons()
{
	UpdateData(TRUE);
	if (change_operation == L"Insert Record") {

		emp_title = L"";
		emp_age = "";
		emp_firstname = "";
		emp_lastname = "";
		emp_address = "";
		emp_jobtitle = "";
		emp_salary = "";
		emp_email = "";
		emp_phonenumber = "";
		emp_gender = "";

		GetDlgItem(IDC_STATIC_TITLE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_EMP_TITLE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO_TITLE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_AGE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_AGE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_FIRST_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_FIRST_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_LAST_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_LAST_NAME)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_GENDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO_GENDER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_EMAIL)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_EMAIL)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_PHONE_NUMBER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_PHONE_NUMBER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_DATE_OF_BIRTH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MONTHCALENDAR1_DATE_BIRTH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_JOB_TITLE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO_JOB_TITLE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_SALARY)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_SALARY)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_HIREDATE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MONTHCALENDAR_EMPLOYEE_HIREDATE)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_INSERT_EMPLOYEE)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_UPDATE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMP_NO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EMP_NO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_CHOOSE_FILED)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_UPDATE_FILED)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_UPDATE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SET_THE_COLUMN)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ENTER_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_CHOOSE_THE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD_TO_SEARCH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ENTER_EMP_DETAILS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ENTER_SEARCH_VALUe)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_LIST_SEARCH_LIST)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);


		GetDlgItem(IDC_LIST_FETCH_ALL_RECORDS)->ShowWindow(SW_HIDE);
	}
	else if (change_operation == L"Delete Record") {
		GetDlgItem(IDC_STATIC_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_EMPLOYEE_NUMBER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_ENTER_EMPLOYEE_NUMBER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_SHOW);



		GetDlgItem(IDC_STATIC_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_CHOOSE_THE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD_TO_SEARCH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ENTER_EMP_DETAILS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ENTER_SEARCH_VALUe)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_LIST_SEARCH_LIST)->ShowWindow(SW_HIDE);


		GetDlgItem(IDC_STATIC_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMP_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DATE_OF_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR1_DATE_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_EMPLOYEE_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_INSERT_EMPLOYEE)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_UPDATE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMP_NO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EMP_NO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_CHOOSE_FILED)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_UPDATE_FILED)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_UPDATE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SET_THE_COLUMN)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_LIST_FETCH_ALL_RECORDS)->ShowWindow(SW_HIDE);

	}
	else if (change_operation == L"Update Reord") {
		GetDlgItem(IDC_STATIC_UPDATE_RECORD)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_EMP_NO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_EMP_NO)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_CHOOSE_FILED)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_UPDATE_FILED)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_UPDATE_EMPLOYEE_RECORD)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_SET_THE_COLUMN)->ShowWindow(SW_SHOW);

		GetDlgItem(IDC_STATIC_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_CHOOSE_THE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD_TO_SEARCH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ENTER_EMP_DETAILS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ENTER_SEARCH_VALUe)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_LIST_SEARCH_LIST)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);


		GetDlgItem(IDC_STATIC_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ENTER_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMP_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DATE_OF_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR1_DATE_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_EMPLOYEE_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_INSERT_EMPLOYEE)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_LIST_FETCH_ALL_RECORDS)->ShowWindow(SW_HIDE);
	}
	else if (change_operation == L"Search Record")
	{

		GetDlgItem(IDC_STATIC_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_CHOOSE_THE_FIELD)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD_TO_SEARCH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_ENTER_EMP_DETAILS)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_EDIT_ENTER_SEARCH_VALUe)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_LIST_SEARCH_LIST)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BUTTON_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_SHOW);


		GetDlgItem(IDC_STATIC_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ENTER_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMP_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DATE_OF_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR1_DATE_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_EMPLOYEE_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_INSERT_EMPLOYEE)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_UPDATE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMP_NO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EMP_NO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_CHOOSE_FILED)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_UPDATE_FILED)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_UPDATE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SET_THE_COLUMN)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_LIST_FETCH_ALL_RECORDS)->ShowWindow(SW_HIDE);
	}
	else if (change_operation == L"Fetch All Records") {
		GetDlgItem(IDC_LIST_FETCH_ALL_RECORDS)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATIC_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMP_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DATE_OF_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR1_DATE_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_EMPLOYEE_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_INSERT_EMPLOYEE)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_UPDATE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMP_NO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EMP_NO)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_CHOOSE_FILED)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_UPDATE_FILED)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_UPDATE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SET_THE_COLUMN)->ShowWindow(SW_HIDE);


		GetDlgItem(IDC_STATIC_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ENTER_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_STATIC_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_CHOOSE_THE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_CHOOSE_FIELD_TO_SEARCH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ENTER_EMP_DETAILS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ENTER_SEARCH_VALUe)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_SEARCH_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);

		emp_data_load();
	}
	else {
		AfxMessageBox(L"Choose Valid Option Form The ComboBox");
	}
	UpdateWindow();
}




void CHomePageDlg::OnBnClickedButtonInsertEmployee()
{
	UpdateData(TRUE); // flow direction database <- ui
	//if (dlg.DoModal() == IDD_DIALOG_INSERT) {

	CDatabase database;
	CString sDsn;
	CString SqlString;

	if (emp_age.IsEmpty()) {
		AfxMessageBox(L"Age Must Be Required ...!");
	}

	else {
		// Build ODBC connection string
		sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\EmployeeDatabase.accdb;Uid=Admin;Pwd=;"));
		TRY{
			// Open the database
			database.Open(NULL,false,false,sDsn);
		//MessageBoxW(L"Are You Sure ?", L"Insert a Record",MB_YESNO);

		CString out = L" ,";
		CString quo = L"'";
		SqlString.Append(_T("INSERT INTO EmployeeTable(Title,Age,FirstName,LastName,Gender,MobilePhone,EMail,BirthDate,Address,JobTitle,Salary,Hiredate) VALUES ("));
		SqlString.Append(quo);
		SqlString.Append(emp_title);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(emp_age);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(emp_firstname);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(emp_lastname);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(emp_gender);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(emp_phonenumber);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(emp_email);
		SqlString.Append(quo);
		SqlString.Append(out);

		COleDateTime dt(emp_datebirth);
		SqlString.Append(quo);
		SqlString.Append(dt.Format(_T("%Y-%m-%d")));
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(emp_address);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(emp_jobtitle);
		SqlString.Append(quo);
		SqlString.Append(out);

		SqlString.Append(quo);
		SqlString.Append(emp_salary);
		SqlString.Append(quo);
		SqlString.Append(out);

		COleDateTime DT(employee_hiredate);
		SqlString.Append(quo);
		SqlString.Append(DT.Format(_T("%Y-%m-%d")));
		SqlString.Append(quo);
		//SqlString.Append(out);


		SqlString.Append(_T(" )"));

		//AfxMessageBox(SqlString);
		database.ExecuteSQL(SqlString);
		MessageBox(L"Insert Record sucessfully...!");
		// Close the database
		database.Close();
		}CATCH(CDBException, e) {
			// If a database exception occured, show error msg
			AfxMessageBox(L"Database error: " + e->m_strError);
		}
		END_CATCH;

		emp_data_load();
		GetDlgItem(IDC_STATIC_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMP_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_AGE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_FIRST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_LAST_NAME)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_GENDER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_EMAIL)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_PHONE_NUMBER)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_ADDRESS)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_DATE_OF_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR1_DATE_BIRTH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_COMBO_JOB_TITLE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT_SALARY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATIC_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_EMPLOYEE_HIREDATE)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BUTTON_INSERT_EMPLOYEE)->ShowWindow(SW_HIDE);

		GetDlgItem(IDC_LIST_FETCH_ALL_RECORDS)->ShowWindow(SW_SHOW);

		UpdateWindow();
	}
}

void CHomePageDlg::OnBnClickedButtonDeleteEmployeeRecord()
{
	UpdateData(TRUE); // flow direction database <- ui
	//if (dlg.DoModal() == IDD_DIALOG_INSERT) {
	CString id = DEmployeeNumber;

	CDatabase database;
	CString sDsn;
	CString SqlString;

	// Build ODBC connection string
	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\EmployeeDatabase.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		database.Open(NULL,false,false,sDsn);
		SqlString = L"DELETE FROM EmployeeTable WHERE EmpID = ";
		SqlString.Append(id);
		//AfxMessageBox(SqlString);
		database.ExecuteSQL(SqlString);


		MessageBox(L"Record Delete sucessfully...!");
		// Close the database
		database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: " + e->m_strError);
	}
	END_CATCH;
	emp_data_load();
	GetDlgItem(IDC_STATIC_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_ENTER_EMPLOYEE_NUMBER)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_DELETE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_LIST_FETCH_ALL_RECORDS)->ShowWindow(SW_SHOW);
	UpdateWindow();
}


void CHomePageDlg::OnBnClickedButtonSearchEmployeeRecord()
{
	UpdateData(TRUE); // flow direction database <- ui
	//if (dlg.DoModal() == IDD_DIALOG_INSERT) {
	CString ChooseField = CChooseFieldSearch;
	CString EnterValue = CEmpSearchDetails;

	CString e_id;
	CString e_age;
	CString e_title;
	CString e_firstname;
	CString e_lastname;
	CString e_gender;
	CString e_phonenumber;
	CString e_email;
	CString e_birthdate;
	CString e_address;
	CString e_jobtitle;
	CString e_salary;
	CString e_hiredate;

	CDatabase database;
	CString sDsn;
	CString SqlString;
	int iRec = 0;
	// Build ODBC connection string
	//sDsn.Format(_T("Driver={ODBC Driver 17 for SQL Server};Server=FYYP1N2;Dbq=C:\\Program Files\\Microsoft SQL Server\\MSSQL15.MSSQLSERVER\\MSSQL\\DATA\\AdminApp.mdf;Trusted_Connection=yes"));

	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\EmployeeDatabase.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		CRecordset recset(&database);
		database.Open(NULL,false,false,sDsn);
	SqlString = L"SELECT * FROM EmployeeTable WHERE ";
	SqlString.Append(ChooseField);
	SqlString.Append(_T(" = "));
	if (ChooseField == L"EmpID") {
		SqlString.Append(EnterValue);
	}
	else {
		SqlString.Append(_T("'" + EnterValue + "'"));
	}
	//AfxMessageBox(SqlString);
	//database.ExecuteSQL(SqlString);

	recset.Open(CRecordset::forwardOnly, SqlString, CRecordset::readOnly);
	ResetListControl();
	ListView_SetExtendedListViewStyle(m_Search_list, LVS_EX_GRIDLINES);
	m_Search_list.InsertColumn(
		0,              // Rank/order of item
		L"EmpID",          // Caption for this header
		LVCFMT_LEFT,    // Relative position of items under header
		100);           // Width of items under header

	m_Search_list.InsertColumn(1, L"Title", LVCFMT_CENTER, 80);
	m_Search_list.InsertColumn(2, L"Age", LVCFMT_LEFT, 100);
	m_Search_list.InsertColumn(3, L"FirstName", LVCFMT_CENTER, 80);
	m_Search_list.InsertColumn(4, L"LastName", LVCFMT_LEFT, 100);
	m_Search_list.InsertColumn(5, L"Gender", LVCFMT_CENTER, 80);
	m_Search_list.InsertColumn(6, L"MobilePhone", LVCFMT_LEFT, 100);
	m_Search_list.InsertColumn(7, L"EMail", LVCFMT_CENTER, 80);
	m_Search_list.InsertColumn(8, L"BirthDate", LVCFMT_LEFT, 100);
	m_Search_list.InsertColumn(9, L"Address", LVCFMT_CENTER, 80);
	m_Search_list.InsertColumn(10, L"JobTitle", LVCFMT_LEFT, 100);
	m_Search_list.InsertColumn(11, L"Salary", LVCFMT_CENTER, 80);
	m_Search_list.InsertColumn(12, L"HireDate", LVCFMT_LEFT, 100);

	while (!recset.IsEOF()) {
		// Copy each column into a variable
		recset.GetFieldValue(L"EmpID", e_id);
		recset.GetFieldValue(L"Title",e_title);
		recset.GetFieldValue(L"Age", e_age);
		recset.GetFieldValue(L"FirstName", e_firstname);
		recset.GetFieldValue(L"LastName", e_lastname);
		recset.GetFieldValue(L"Gender", e_gender);
		recset.GetFieldValue(L"MobilePhone", e_phonenumber);
		recset.GetFieldValue(L"EMail", e_email);
		recset.GetFieldValue(L"BirthDate", e_birthdate);
		recset.GetFieldValue(L"Address", e_address);
		recset.GetFieldValue(L"JobTitle", e_jobtitle);
		recset.GetFieldValue(L"Salary", e_salary);
		recset.GetFieldValue(L"Hiredate", e_hiredate);

		// Insert values into the list control
		iRec = m_Search_list.InsertItem(0, e_id, 0);
		m_Search_list.SetItemText(0, 1, e_title);
		m_Search_list.SetItemText(0, 2, e_age);
		m_Search_list.SetItemText(0, 3, e_firstname);
		m_Search_list.SetItemText(0, 4, e_lastname);
		m_Search_list.SetItemText(0, 5, e_gender);
		m_Search_list.SetItemText(0, 6, e_phonenumber);
		m_Search_list.SetItemText(0, 7, e_email);
		m_Search_list.SetItemText(0, 8, e_birthdate);
		m_Search_list.SetItemText(0, 9, e_address);
		m_Search_list.SetItemText(0, 10, e_jobtitle);
		m_Search_list.SetItemText(0, 11, e_salary);
		m_Search_list.SetItemText(0, 12, e_hiredate);

		// goto next record
		recset.MoveNext();
	}
	MessageBox(L"Record Found sucessfully...!");
	// Close the database
	database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: " + e->m_strError);
	}
	END_CATCH;
	ChooseField.Empty();
	CEmpSearchDetails.Empty();
	UpdateWindow();
}
void CHomePageDlg::ResetListControl() {
	m_Search_list.DeleteAllItems();
	int iNbrOfColumns = 0, i;
	CHeaderCtrl* pHeader = (CHeaderCtrl*)m_Search_list.GetDlgItem(0);
	if (pHeader) {
		iNbrOfColumns = pHeader->GetItemCount();
	}
	for (i = iNbrOfColumns; i >= 0; i--) {
		m_Search_list.DeleteColumn(i);
	}
}
void CHomePageDlg::m_ResetListControl() {
	emp_list.DeleteAllItems();
	int iNbrOfColumns = 0, i;
	CHeaderCtrl* pHeader = (CHeaderCtrl*)emp_list.GetDlgItem(0);
	if (pHeader) {
		iNbrOfColumns = pHeader->GetItemCount();
	}
	for (i = iNbrOfColumns; i >= 0; i--) {
		emp_list.DeleteColumn(i);
	}
}
void CHomePageDlg::OnBnClickedButtonUpdateEmployeeRecord()
{
	UpdateData(TRUE); // flow direction database <- ui

	CString EmpID = uemp_no;
	CString ChooseField = UChooseField;
	CString EnterValue = Update_Field_Value;
	COleDateTime DT(UpdateDate);
	CString date_value;
	date_value.Append(DT.Format(_T("%Y-%m-%d")));

	CDatabase database;
	CString sDsn;
	CString SqlString;
	// Build ODBC connection string
	sDsn.Format(_T("Driver={Microsoft Access Driver (*.mdb, *.accdb)};Dbq=C:\\Users\\admin.teja\\Documents\\EmployeeDatabase.accdb;Uid=Admin;Pwd=;"));
	TRY{
		// Open the database
		database.Open(NULL,false,false,sDsn);
	SqlString = L"UPDATE EmployeeTable SET ";
	SqlString.Append(ChooseField);
	SqlString.Append(_T(" = "));
	if (ChooseField == L"Hiredate" || ChooseField == L"BirthDate") {
		SqlString.Append(_T("'" + date_value + "'"));
	}
	else {

		SqlString.Append(_T("'" + EnterValue + "'"));
	}
	SqlString.Append(_T(" WHERE EmpId =" + EmpID));

	//AfxMessageBox(SqlString);
	//database.ExecuteSQL(SqlString);
	database.ExecuteSQL(SqlString);

	MessageBox(L"Record Update sucessfully...!");
	// Close the database
	database.Close();
	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: " + e->m_strError);
	}
	END_CATCH;
	emp_data_load();
	GetDlgItem(IDC_STATIC_UPDATE_RECORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_EMP_NO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_EMP_NO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_CHOOSE_FILED)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_COMBO_CHOOSE_FIELD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC_UPDATE_FILED)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_UPDATE_EMPLOYEE_RECORD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUTTON_SET_THE_COLUMN)->ShowWindow(SW_HIDE);
	EmpID.Empty();
	ChooseField.Empty();
	EnterValue.Empty();
	UpdateDate.null;

	GetDlgItem(IDC_LIST_FETCH_ALL_RECORDS)->ShowWindow(SW_SHOW);
	UpdateWindow();
}


void CHomePageDlg::OnCbnSelchangeComboChooseField()
{

}

void CHomePageDlg::OnCbnDropdownComboChooseField()
{
	//GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
	//GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);

}


void CHomePageDlg::OnCbnEditupdateComboChooseField()
{

}


void CHomePageDlg::OnCbnEditchangeComboChooseField()
{

}


void CHomePageDlg::OnStnClickedStaticUpdateFiled()
{
	// TODO: Add your control notification handler code here
}


void CHomePageDlg::OnBnClickedButtonSetTheColumn()
{
	UpdateData(TRUE);
	GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
	if (UChooseField == L"BirthDate" || UChooseField == L"Hiredate") {
		GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_SHOW);
	}
	else {
		GetDlgItem(IDC_EDIT_UPDATE_FIELD)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_MONTHCALENDAR_UPDATE_DATE)->ShowWindow(SW_HIDE);
	}
	UpdateWindow();
}



void CHomePageDlg::OnStnClickedStaticEnterEmpDetails()
{
	// TODO: Add your control notification handler code here
}
