#pragma once

void InitData();

void LoadData();

void save_athlete(char*);

void save_organization (struct __OrgTable*, char* );

void load_organization(struct __OrgTable*, char* );

void load_athlete(struct __AHashMap*, char* );